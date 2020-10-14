--1. Các product có đơn giá lớn hơn đơn giá trung bình của các product.
--
SELECT DISTINCT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P ON OD.[ProductID] = P.[ProductID]
WHERE OD.[UnitPrice] >
	(SELECT AVG ( OD.[UnitPrice])
	FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P ON OD.[ProductID] = P.[ProductID])
--
SELECT DISTINCT [ProductID], [ProductName], [UnitPrice]
FROM [dbo].[Products]
WHERE [UnitPrice] >
	(SELECT AVG ([UnitPrice])
	FROM [dbo].[Products])
--
--2. Các product có đơn giá lớn hơn đơn giá trung bình của các product có ProductName bắt đầu là ‘N’
--
SELECT DISTINCT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P ON OD.[ProductID] = P.[ProductID]
WHERE OD.[UnitPrice] >
	(SELECT AVG ( OD.[UnitPrice])
	FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P ON OD.[ProductID] = P.[ProductID]
	WHERE P.[ProductName] LIKE 'N%')
--
SELECT DISTINCT [ProductID], [ProductName], [UnitPrice]
FROM [dbo].[Products]
WHERE [UnitPrice] >
	(SELECT AVG ( [UnitPrice])
	FROM [dbo].[Products]
	WHERE [ProductName] LIKE 'N%')
--
--3. Cho biết những sản phẩm có tên bắt đầu bằng chữ N và đơn giá > đơn giá trung binh của sản phẩm khác
--
SELECT DISTINCT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P ON OD.[ProductID] = P.[ProductID]
WHERE P.[ProductName] LIKE 'N%' AND OD.[UnitPrice] >
	(SELECT AVG ( OD.[UnitPrice])
	FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P ON OD.[ProductID] = P.[ProductID]
	WHERE P.[ProductName] NOT LIKE 'N%')
--
--4. Danh sách các products đã có khách hàng đặt hàng (tức là ProductId có trong Order Details).
--Thông tin bao gồm ProductId, ProductName, Unitprice.
--
SELECT DISTINCT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P ON OD.[ProductID] = P.[ProductID]
-- 
SELECT * FROM [dbo].[Products]
WHERE [ProductID] IN (SELECT [ProductID] FROM [dbo].[Order Details])
--
--5. Danh sách các products có đơn giá nhập lớn hơn đơn giá bán nhỏ nhất của tất cả các Products
--
SELECT DISTINCT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.[ProductID]
WHERE  OD.[UnitPrice] > ANY (SELECT [UnitPrice] FROM [dbo].[Order Details])
ORDER BY OD.[UnitPrice]
--
--6. Danh sách các hóa đơn của những Customers mà Customers ở thành phố LonDon và Madrid.
--
SELECT * FROM [dbo].[Orders]
WHERE [CustomerID] IN (SELECT [CustomerID] FROM [dbo].[Customers] WHERE [City] = 'LonDon' OR [City] = 'Madrid')
--
--7. Danh sách các products có đơn vị tính có chữ Box và có đơn giá mua nhỏ hơn đơn giá trung bình của tất cả các Products.
--
SELECT * FROM [dbo].[Products]
WHERE [QuantityPerUnit] LIKE '%Box%' AND [UnitPrice] < (SELECT AVG ([UnitPrice]) FROM [dbo].[Products])
--
--8. Danh sách các Products có số lượng (Quantity) bán được lớn nhất.
--
SELECT P.[ProductID], P.[ProductName], OD.[Quantity]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.ProductID
WHERE OD.[Quantity] >= ALL (SELECT [Quantity] FROM [dbo].[Order Details])
--
--9. Danh sách các Customer chưa từng lập hóa đơn (viết bằng ba cách: dùng NOT EXISTS, dùng LEFT JOIN, dùng NOT IN )
--
SELECT * FROM [dbo].[Customers]
WHERE [CustomerID] NOT IN (SELECT [CustomerID] FROM [dbo].[Orders]
							WHERE [dbo].[Customers].CustomerID = [dbo].[Orders].CustomerID)
--
SELECT C.[CustomerID], C.[CompanyName] FROM [dbo].[Customers] C LEFT JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
WHERE O.[OrderID] IS NULL
--
SELECT * FROM [dbo].[Customers]
WHERE NOT EXISTS (SELECT [CustomerID] FROM [dbo].[Orders])
--
--10.Cho biết các sản phẩm có đơn giá bán cao nhất
--
SELECT DISTINCT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.ProductID
WHERE OD.[UnitPrice] >= ALL (SELECT [UnitPrice] FROM [dbo].[Order Details])
--
--11.Cho biết các sản phẩm có đơn vị tính có chứa chữ box và có đơn giá bán cao nhất
--
SELECT DISTINCT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.ProductID
WHERE OD.[UnitPrice] >= ALL (SELECT OD.[UnitPrice] 
							FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P
							ON P.[ProductID] = OD.ProductID
							WHERE P.[QuantityPerUnit] LIKE '%box%' )
--
--12.Danh sách các products có đơn giá bán lớn hơn đơn giá bán trung bình của các Products có ProductId<=5
--
SELECT DISTINCT P.[ProductID], P.[ProductName], OD.[UnitPrice]
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.ProductID
WHERE OD.[UnitPrice] > (SELECT AVG (OD.[UnitPrice])
							FROM [dbo].[Order Details] OD JOIN [dbo].[Products] P
							ON P.[ProductID] = OD.ProductID
							WHERE P.[ProductID] <= 5 )
--
--13.Danh sách các Customers và các Employees không ở cùng thành phố
--
SELECT DISTINCT C.[CustomerID], C.[CompanyName],C.[City], E.[EmployeeID], Name_E = [FirstName] + ' ' + [LastName], E.[City]
FROM [dbo].[Customers] C, [dbo].[Employees] E 
WHERE C.[CustomerID] NOT IN (SELECT [CustomerID]
							FROM [dbo].[Customers] C JOIN [dbo].[Employees] E ON C.[City] = E.[City])
	AND E.[EmployeeID] NOT IN (SELECT [EmployeeID]
							FROM [dbo].[Customers] C JOIN [dbo].[Employees] E ON C.[City] = E.[City])
--
--14.Cho biết những sản phẩm nào có tổng số lượng bán được lớn hơn số lượng trung bình bán ra
--
SELECT DISTINCT P.[ProductID], P.[ProductName] 
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.ProductID
WHERE OD.[Quantity] > (SELECT AVG ([Quantity]) FROM [dbo].[Order Details])
ORDER BY P.ProductID
--
--15.Liệt kê danh sách các khách hàng mua các hóa đơn mà các hóa đơn này chỉ mua những sản phẩm có mã >=3
--
SELECT * FROM [dbo].[Customers]
WHERE [CustomerID] IN (SELECT O.[CustomerID] FROM [dbo].[Orders] O JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID]
						WHERE OD.[ProductID] >= 3)
--
--16.Liệt kê danh sách các khách hàng mà các khách hàng này mua các hóa đơn do các nhân viên lập hóa đơn ở cùng thành phố với khách hàng
--
SELECT * FROM [dbo].[Customers]
WHERE [CustomerID] IN ( SELECT O.[CustomerID] FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID] JOIN [dbo].[Employees] E ON O.[EmployeeID] = E.[EmployeeID]
						WHERE C.[City] = E.[City])
--
--17.Danh sách các Customers mà các Customers đã mua hàng trong tháng 7, 9 năm 1997
--
SELECT * FROM [dbo].[Customers]
WHERE [CustomerID] IN ( SELECT O.[CustomerID] FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
						WHERE MONTH(O.[OrderDate]) = 7 OR MONTH(O.[OrderDate]) =9 AND YEAR(O.[OrderDate]) = 1997)
--
--18.Danh sách các City có nhiều hơn 3 customer.
--
SELECT [City] FROM [dbo].[Customers]
GROUP BY [City]
HAVING COUNT([CustomerID]) > 3
--
--19.Tìm tất cả các Customers mua ít nhất 2 đơn hàng.
--
SELECT * FROM [dbo].[Customers]
WHERE [CustomerID] IN (
						SELECT [CustomerID] FROM [dbo].[Orders]
						GROUP BY [CustomerID]
						HAVING COUNT([OrderID]) >= 2)
--
--20.Bạn hãy đưa ra câu hỏi cho 3 câu truy vấn sau:
	-- Tìm tất cả Product có Unitprice lớn hơn Unitprice lớn nhất của các Product có tên bắt đầu bằng 'B'.
	Select ProductId, ProductName, UnitPrice from [Products]
	Where Unitprice > ALL (Select Unitprice from [Products] where ProductName like 'B%')
	--
	-- Tìm tất cả Product có Unitprice lớn hơn Unitprice nhỏ nhất của các Product có tên bắt đầu bằng 'B'.
	Select ProductId, ProductName, UnitPrice from [Products]
	Where Unitprice>ANY (Select Unitprice from [Products] where
	ProductName like 'B%')
	--
	---- Tìm tất cả Product có Unitprice bằng với Unitprice của các Product có tên bắt đầu bằng 'B'.
	Select ProductId, ProductName, UnitPrice from [Products]
	Where Unitprice=ANY (Select Unitprice from [Products] where
	ProductName like 'B%')