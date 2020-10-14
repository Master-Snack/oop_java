--Bùi Binh Minh
--ket nhom

USE [Northwind]
SET DATEFORMAT DMY

--1.Danh sách các orders ứng với tổng tiền của từng hóa đơn.
--Thông tin bao gồm OrdersId, OrderDate, TotalAccount. Trong đó TotalAccount là Sum của Quantity * Unitprice, kết nhóm theo OrderId.
--
SELECT O.[OrderID],[OrderDate],TotalAccount = SUM([Quantity]*[UnitPrice])
FROM [dbo].[Orders] O JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID]
GROUP BY O.[OrderID], [OrderDate]
--
--2. Danh sách các orders ứng với tổng tiền của từng hóa đơn có Shipcity là ‘Madrid’. Thông tin bao gồm OrdersId, OrderDate, TotalAccount.
--Trong đó TotalAccount là Sum của Quantity * Unitprice, kết nhóm theo OrderId. 
--
SELECT O.[OrderID], [OrderDate], TotalAccount = SUM([Quantity]*[UnitPrice])
FROM [dbo].[Orders] O JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID]
WHERE [ShipCity] = 'Madrid'
GROUP BY O.[OrderID], [OrderDate]
--
--3. Danh sách các products có tổng số lượng lập hóa đơn lớn nhất. 
--
SELECT TOP 1 WITH TIES P.[ProductID], P.[ProductName], SOLUONG = COUNT(OD.[ProductID])
FROM [dbo].[Products] P JOIN [dbo].[Order Details] OD ON P.[ProductID] = OD.[ProductID]
GROUP BY P.[ProductID], P.[ProductName]
ORDER BY SOLUONG DESC
--
--4. Cho biết mỗi customers đã lập bao nhiêu hóa đơn. Thông tin gồm CustomerID, CompanyName, CountOfOrder.
--Trong đó  CountOfOrder (tổng số hóa đơn) được đếm (Count) theo từng Customers. 
--
SELECT C.[CustomerID], [CompanyName], CountOfOrder = COUNT (O.[CustomerID])
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
GROUP BY C.[CustomerID], [CompanyName]
--
--5. Cho biết mỗi Employee đã lập được bao nhiêu hóa đơn, ứng với tổng tiền. 
--
SELECT E.[EmployeeID],NameEP=[FirstName]+' '+[LastName], SoLuongHD = COUNT (O.[EmployeeID]), TongTien = SUM(OD.[UnitPrice]*OD.[Quantity])
FROM [dbo].[Employees] E JOIN [dbo].[Orders] O ON E.[EmployeeID] = O.[EmployeeID] JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID]
GROUP BY E.[EmployeeID],[FirstName]+' '+[LastName]
--
--6. Danh sách các customer ứng với tổng tiền các hoá đơn được lập từ 31/12/1996 đến 1/1/1998.
--
SELECT C.[CustomerID],[CompanyName],TongTien = SUM (OD.[UnitPrice]*OD.[Quantity])
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID] JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID]
WHERE [OrderDate] BETWEEN '31/12/1996' AND '1/1/1998'
GROUP BY C.[CustomerID],[CompanyName]
--
--7. Danh sách các customer ứng với tổng tiền các hoá đơn, mà các hóa đơn được lập từ 31/12/1996 đến 1/1/1998 và tổng tiền các hóa đơn >20000. 
--
SELECT C.[CustomerID],[CompanyName],TongTien = SUM (OD.[UnitPrice]*OD.[Quantity])
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID] JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID]
WHERE [OrderDate] BETWEEN '31/12/1996' AND '1/1/1998'
GROUP BY C.[CustomerID],[CompanyName]
HAVING SUM(OD.[UnitPrice]*OD.[Quantity])>20000
--
--8. Danh sách các customer ứng với tổng số hoá đơn, tổng tiền các hoá đơn, mà các hóa đơn được lập từ 31/12/1996 đến 1/1/1998 và tổng tiền các hóa đơn >20000. 
--Thông tin được sắp xếp theo CustomerID, cùng mã thì sắp xếp theo tổng tiền giảm dần.
-- 
SELECT O.[CustomerID],[CompanyName],[Address],TONGSOHD = COUNT(O.CUSTOMERID), TONGTIEN =SUM(UNITPRICE*QUANTITY)
FROM [dbo].[Customers] C JOIN Orders O ON C.CustomerID=O.CustomerID JOIN [Order Details] OD ON OD.OrderID=O.OrderID
WHERE ORDERDATE BETWEEN '31/12/1996' AND '1/1/1998'
GROUP BY O.[CustomerID],[CompanyName],[Address]
HAVING SUM(UNITPRICE*QUANTITY)>20000
ORDER BY O.CustomerID,TONGTIEN DESC
--
--9. Danh sách các Category có tổng số lượng tồn (UnitsInStock) lớn hơn 300, đơn giá trung bình nhỏ hơn 25.
--Thông tin kết quả bao gồm CategoryID, CategoryName, Total_UnitsInStock, Average_Unitprice. 
--
SELECT CA.[CategoryID],CA.[CategoryName], Total_UnitsInStock = SUM(P.[UnitsInStock]), Average_Unitprice = SUM(P.[UnitPrice])/COUNT(P.[ProductID])
FROM [dbo].[Products] P JOIN [dbo].[Categories] CA ON P.[CategoryID] = CA.[CategoryID]
GROUP BY CA.[CategoryID],CA.[CategoryName]
HAVING SUM(P.[UnitsInStock])>300 AND (SUM(P.[UnitPrice])/COUNT(P.[ProductID]))<25
--
--10. Danh sách các Category có tổng số product lớn hớn 10.Thông tin kết quả bao gồm CategoryID, CategoryName, Total_UnitsInStock. 
--
SELECT CA.[CategoryID],CA.[CategoryName],Total_Products = COUNT(P.[ProductID]),Total_UnitsInStock = SUM(P.[UnitsInStock])
FROM [dbo].[Products] P JOIN [dbo].[Categories] CA ON P.[CategoryID] = CA.[CategoryID]
GROUP BY CA.[CategoryID],CA.[CategoryName]
HAVING COUNT(P.[ProductID])>10
--
--11. Danh sách các product theo từng CategoryName, thông tin bao gồm: Productname, CategoryName, Unitprice, đơn giá trung bình,
--tổng số lượng tồn (sum of UnitsinStock) theo từng CategoryName. 
--
SELECT CA.[CategoryName], P.[ProductName],[UnitPrice], Total_UnitsInStock = SUM(P.[UnitsInStock]), Average_Unitprice = SUM(P.[UnitPrice])/COUNT(P.[ProductID])
FROM [dbo].[Products] P JOIN [dbo].[Categories] CA ON P.[CategoryID] = CA.[CategoryID]
GROUP BY  CA.[CategoryID], CA.[CategoryName], P.[ProductName],[UnitPrice]
ORDER BY  [CategoryName]
--
--12. Danh sách các Customer ứng với tổng tiền của các hóa đơn ở từng tháng. Thông tin bao gồm CustomerID, CompanyName, Month_Year, Total. 
--Trong đó Month_year là tháng và năm lập hóa đơn, Total là tổng của Unitprice* Quantity, có thống kế tổng của total theo từng Customer và Month_Year .
--
SELECT O.[CustomerID],[CompanyName],[Address],Month_Year =CONVERT(CHAR(2),MONTH(ORDERDATE))+'/'+CONVERT(CHAR(4),YEAR(ORDERDATE)), TONGTIEN =SUM(UNITPRICE*QUANTITY)
FROM [dbo].[Customers] C JOIN Orders O ON C.CustomerID=O.CustomerID JOIN [Order Details] OD ON OD.OrderID=O.OrderID
GROUP BY O.[CustomerID],[CompanyName],[Address],CONVERT(CHAR(2),MONTH(ORDERDATE))+'/'+CONVERT(CHAR(4),YEAR(ORDERDATE))
ORDER BY Month_Year,TONGTIEN DESC
--
--13. Cho biết Employees nào bán được nhiều tiền nhất trong 7 của năm 1997 
--
SELECT TOP 1 WITH TIES E.[EmployeeID],NameEP = [FirstName] + ' '+ [LastName], TongTien = SUM(OD.[UnitPrice]*OD.[Quantity])
FROM [dbo].[Employees] E JOIN [dbo].[Orders] O ON E.[EmployeeID] = O.[EmployeeID] JOIN [dbo].[Order Details] OD ON O.[OrderID] = OD.[OrderID]
WHERE [OrderDate] BETWEEN '1/7/1997' AND '31/7/1997'
GROUP BY E.[EmployeeID], [FirstName] + ' '+ [LastName]
ORDER BY TongTien DESC
--
--14. Danh sách 3 khách có nhiều đơn hàng nhất của năm 1996. 
--
SELECT TOP 3 WITH TIES C.[CustomerID], C.[CompanyName], SoDonHang = COUNT (O.[CustomerID])
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
WHERE [OrderDate] BETWEEN '1/1/1996' AND '31/12/1996'
GROUP BY C.[CustomerID], C.[CompanyName]
ORDER BY SoDonHang DESC
--
--15. Cho biết khách hàng nào có số lần mua hàng lớn hơn 10 trong năm 1997. 
--
SELECT C.[CustomerID], C.[CompanyName], SoDonHang = COUNT (O.[CustomerID])
FROM [dbo].[Customers] C JOIN [dbo].[Orders] O ON C.[CustomerID] = O.[CustomerID]
WHERE [OrderDate] BETWEEN '1/1/1997' AND '31/12/1997'
GROUP BY C.[CustomerID], C.[CompanyName]
HAVING COUNT (O.[CustomerID])>10
--