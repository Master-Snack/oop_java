--1
SELECT * FROM dbo.Customers
WHERE CustomerID NOT IN (SELECT CustomerID FROM dbo.Orders WHERE MONTH(OrderDate) =7 AND YEAR(OrderDate) = 1997)
--2
SELECT * FROM dbo.Customers INNER JOIN dbo.Orders ON Orders.CustomerID = Customers.CustomerID
WHERE MONTH(OrderDate) =7 AND YEAR(OrderDate) = 1997 AND DAY(OrderDate) <=15
--3
SET DATEFORMAT DMY
SELECT * FROM (([dbo].[Products] p INNER JOIN [dbo].[Order Details] od ON p.ProductID = od.ProductID)
INNER JOIN [dbo].[Orders] o ON o.OrderID = od.OrderID)
WHERE OrderDate = '16/07/1996'
--4
SELECT o.OrderID, c.CustomerID, o.OrderDate, o.RequiredDate FROM dbo.Customers c INNER JOIN dbo.Orders o ON o.CustomerID = c.CustomerID
WHERE MONTH(o.OrderDate) IN (4, 9) AND YEAR(o.OrderDate) =1997
ORDER BY c.CompanyName DESC, o.OrderDate DESC
--5
SELECT * FROM dbo.Orders o INNER JOIN dbo.Employees e ON e.EmployeeID = o.EmployeeID
WHERE e.LastName LIKE 'Fuller'
--6
SELECT DISTINCT * FROM (((dbo.Products p INNER JOIN dbo.Suppliers s ON s.SupplierID = p.SupplierID)
INNER JOIN dbo.[Order Details] od ON od.ProductID = p.ProductID)
INNER JOIN dbo.Orders o ON o.OrderID= od.OrderID)
WHERE p.SupplierID IN (1,3,6) AND MONTH(o.OrderDate) IN (6,7) AND YEAR(o.OrderDate) = 1997
ORDER BY p.SupplierID, p.ProductID
--7
SELECT * FROM dbo.Products p INNER JOIN dbo.[Order Details] od ON od.ProductID = p.ProductID
WHERE od.Discount = 1
--8
SELECT * FROM dbo.Products p INNER JOIN dbo.[Order Details] od ON od.ProductID = p.ProductID
WHERE od.UnitPrice = p.UnitPrice
--9
SELECT * FROM ((dbo.Products p INNER JOIN dbo.[Order Details] od ON od.ProductID = p.ProductID)
INNER JOIN dbo.Orders o ON o.OrderID = od.OrderID)
WHERE od.OrderID = '10248'
--10
SELECT * FROM dbo.Employees e INNER JOIN dbo.Orders o ON o.EmployeeID = e.EmployeeID
WHERE  MONTH(o.OrderDate) = 7 AND YEAR(o.OrderDate) = 1996
--11
SELECT * FROM dbo.Products WHERE NOT EXISTS (
SELECT * FROM  ((dbo.Products d INNER JOIN dbo.[Order Details] od ON od.ProductID = d.ProductID)
INNER JOIN dbo.Orders o ON o.OrderID = od.OrderID)
WHERE MONTH(o.OrderDate) = 6 AND YEAR(o.OrderDate) = 1996)

--where MONTH(OrderDate)=6 and YEAR(OrderDate)=1997)--
--where month(orderdate) in ('1','2','3') and year(orderdate)=1998

--Danh sách các Employes không lập hóa đơn vào ngày hôm nay--
select *
from dbo.Employees
where EmployeeID not in
(select e.EmployeeID
from  dbo.Employees e join dbo.Orders o on e.EmployeeID=o.EmployeeID
where o.OrderDate = GETDATE())

--Danh sách các Customers chưa mua hàng trong năm 1997--
select *
from dbo.Customers
where CustomerID not in
(select c.CustomerID
from dbo.Customers c join dbo.Orders o on o.CustomerID=c.CustomerID
where year(o.OrderDate) = 1997)

--Danh sách các nhà cung cấp Suppliers không cung cấp Products có mã là 59.--
select *
from dbo.Suppliers
where SupplierID not in
(select s.SupplierID
from dbo.Products p join dbo.Suppliers s on p.SupplierID = s.SupplierID
where p.ProductID=59)

--Tìm tất cả các Customers mua ít nhất 2 đơn hàng.--
select distinct o1.CustomerID, c.CompanyName
from dbo.Orders o1 join dbo.Orders o2 on o1.CustomerID=o2.CustomerID 
join dbo.Customers c on c.CustomerID=o1.CustomerID
where o1.OrderID<>o2.OrderID
