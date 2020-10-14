USE [Northwind]
SET DATEFORMAT DMY
--1. Liệt kê các customer không có lập hóa đơn trong tháng 7/1997
--
SELECT C.[CustomerID],C.[CompanyName]
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
WHERE MONTH([OrderDate]) = '7'
GROUP BY C.[CustomerID],C.[CompanyName]
HAVING COUNT (O.[OrderID]) = 0
--
--2. Liệt kê các customer có lập hóa đơn trong 15 ngày đầu tiên của 7/1997
--
SELECT C.[CustomerID],C.[CompanyName],SoHD = COUNT (O.[OrderID])
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
WHERE [OrderDate] BETWEEN '1/7/1997' AND '15/7/1997'
GROUP BY C.[CustomerID],C.[CompanyName]
--
--3. Liệt kê danh sách các sản phẩm được giao vào ngày 16/7/1996
--
SELECT P.[ProductID], P.[ProductName]
FROM [dbo].[Orders] O JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID] JOIN [Products] P ON OD.[ProductID] = P.[ProductID]
WHERE [ShippedDate] = '16/7/1996'
GROUP BY P.[ProductID], P.[ProductName]
--
/*4. Liệt kê danh sách các hóa đơn của các Customers mua hàng trong tháng 4,
9 của năm 1997. Thông tin gồm Orderid, CompanyName, OrderDate,
RequiredDate, được sắp xếp theo CompanyName, cùng Companyname thì
theo OrderDate giảm dần.*/
--
SELECT C.[CustomerID], C.[CompanyName], O.[OrderDate], O.[RequiredDate]
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
WHERE MONTH(O.[OrderDate]) = '4'
GROUP BY C.[CustomerID], C.[CompanyName], O.[OrderDate], O.[RequiredDate]
ORDER BY C.[CompanyName] , O.[OrderDate] DESC
--
--5. Liệt kê danh sách các hóa đơn do nhân viên có Lastname là Fuller lập.
SELECT [OrderID]
FROM [dbo].[Orders] O JOIN [dbo].[Employees] E ON  O.[EmployeeID] = E.[EmployeeID]
WHERE E.[LastName] = 'Fuller'
GROUP BY [OrderID]
--
/*6. Liệt kê danh sách các Products do nhà cung cấp (supplier) có mã 1,3,6 bán
được trong tháng 6,7 của năm 1997, được sắp xếp theo mã nhà cung cấp
(SupplierID), cùng mã nhà cung cấp thì sắp xếp theo ProductID.*/
--
SELECT P.[ProductID],P.[ProductName],S.[SupplierID], O.[OrderDate]
FROM [dbo].[Suppliers] S JOIN [dbo].[Products] P ON S.[SupplierID] = P.[SupplierID] JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.[ProductID] JOIN [dbo].[Orders] O ON OD.[OrderID] = O.[OrderID]
WHERE MONTH([OrderDate]) = '6' OR MONTH([OrderDate]) = '7'
GROUP BY P.[ProductID],P.[ProductName],S.[SupplierID], O.[OrderDate]
ORDER BY  [SupplierID],[ProductID]
--
--7. Liệt kê danh sách các Products có Discount là 1
--
SELECT P.[ProductID], P.[ProductName]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.[ProductID]
WHERE OD.[Discount] = 1
GROUP BY P.[ProductID], P.[ProductName]
--
--8. Liệt kê danh sách các Products có đơn giá bán bằng đơn giá mua.
--
SELECT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.[ProductID]
WHERE P.[UnitPrice] = OD.[UnitPrice]
GROUP BY P.[ProductID], P.[ProductName], OD.[UnitPrice]
--
--9. Liệt kê danh sách các Products mà hóa đơn có OrderID là 10248 đã mua.
--
SELECT P.[ProductID], P.[ProductName]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.[ProductID]
WHERE OD.[OrderID] = 10248
GROUP BY P.[ProductID], P.[ProductName]
--
--10.Liệt kê danh sách các Employers đã lập các hóa đơn trong tháng 7 của năm 1996
--
SELECT E.[EmployeeID], Name_E = [FirstName] + ' ' +[LastName]
FROM [dbo].[Employees] E JOIN [dbo].[Orders] O ON E.[EmployeeID] = O.[EmployeeID]
WHERE MONTH([OrderDate]) = '7'
GROUP BY E.[EmployeeID], [FirstName] + ' ' +[LastName]
--
--11.Liệt kê danh sách các sản phẩm Producrs chưa bán được trong tháng 6 năm 1996
-- danh sách Producrs đã bán được trong tháng 6 năm 1996
SELECT P.[ProductID], P.[ProductName], O.[OrderDate]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.[ProductID] JOIN [dbo].[Orders] O ON O.[OrderID] = OD.[OrderID]
WHERE YEAR(O.[OrderDate]) = '1996'
GROUP BY P.[ProductID], P.[ProductName], O.[OrderDate]
ORDER BY O.[OrderDate]
-- danh sách các sản phẩm Producrs chưa bán được trong tháng 6 năm 1996
SELECT [ProductID], [ProductName] FROM [dbo].[Products]
EXCEPT(
	SELECT P.[ProductID], P.[ProductName]
	FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.[ProductID] JOIN [dbo].[Orders] O ON O.[OrderID] = OD.[OrderID]
	WHERE MONTH(O.[OrderDate]) = '6'
	GROUP BY P.[ProductID], P.[ProductName])
--
--12.Liệt kê danh sách các Employes không lập hóa đơn vào ngày hôm nay
--
SELECT [EmployeeID], [FirstName], [LastName] FROM [dbo].[Employees]
EXCEPT(
	SELECT E.[EmployeeID], E.[FirstName], E.[LastName]
	FROM [dbo].[Employees] E JOIN [dbo].[Orders] O ON E.[EmployeeID] = O.[EmployeeID]
	WHERE DAY(O.[OrderDate]) = DAY(GETDATE()) AND MONTH(O.[OrderDate]) = MONTH(GETDATE()) AND YEAR(O.[OrderDate]) = YEAR(GETDATE())
	GROUP BY E.[EmployeeID], E.[FirstName], E.[LastName])
--
--13.Liệt kê danh sách các Customers chưa mua hàng trong năm 1997
--
SELECT [CustomerID], [CompanyName] FROM [dbo].[Customers]
EXCEPT(
	SELECT C.[CustomerID], C.[CompanyName]
	FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
	WHERE YEAR([OrderDate]) = '1997'
	GROUP BY C.[CustomerID], C.[CompanyName])
--
--14.Liệt kê danh sách các nhà cung cấp Suppliers không cung cấp Products có mã là 59.
--
SELECT [SupplierID],[CompanyName] FROM [dbo].[Suppliers]
EXCEPT(
	SELECT S.[SupplierID], S.[CompanyName]
	FROM [dbo].[Suppliers] S JOIN [dbo].[Products] P ON S.[SupplierID] = P.[SupplierID]
	WHERE P.[ProductID] = '59'
	GROUP BY S.[SupplierID], S.[CompanyName])
--
--15.Tìm tất cả các Customers mua các sản phẩm có tên bắt đầu bằng chữ T trong tháng 7.
--
SELECT C.[CustomerID], C.[CompanyName], P.[ProductName]
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.CustomerID JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID] JOIN [dbo].[Products] P ON OD.[ProductID] = P.[ProductID]
WHERE MONTH([OrderDate]) = '7'
GROUP BY C.[CustomerID], C.[CompanyName], P.[ProductName]