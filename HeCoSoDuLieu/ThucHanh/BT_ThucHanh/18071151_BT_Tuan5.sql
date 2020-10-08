--1
SELECT * FROM dbo.Products
--2
SELECT CustomerID, CompanyName, City, Phone FROM dbo.Customers
--3
SELECT ProductID, ProductName, UnitPrice FROM dbo.Products
--4
SELECT EmployeeID, LastName+FirstName AS EmployeeName ,HomePhone AS Phone, YEAR(GETDATE()) - YEAR(BirthDate) AS Age FROM dbo.Employees
--5
SELECT * FROM dbo.Customers
WHERE ContactTitle LIKE 'O%'
--6
SELECT * FROM dbo.Customers
WHERE City = 'Paris'
--7
SELECT * FROM dbo.Customers
WHERE City = 'LonDon' OR City = 'Boise' OR City = 'Paris'
--8
SELECT *FROM dbo.Customers
WHERE CompanyName LIKE 'V%' AND City = 'Lyon'
--9
SELECT * FROM dbo.Customers
WHERE Fax IS NULL
--10
SELECT * FROM dbo.Customers
WHERE Fax IS NOT NULL
--11
SELECT * FROM dbo.Employees
WHERE YEAR(BirthDate) <= 1960
--12
SELECT * FROM dbo.Products
WHERE QuantityPerUnit LIKE '%Boxes%'
--13
SELECT * FROM dbo.Products
WHERE UnitPrice > 10 AND UnitPrice < 15
--14
SELECT * FROM dbo.Orders
WHERE YEAR(OrderDate) = 1996 AND MONTH(OrderDate) = 9
--15
SELECT ProductID, ProductName, UnitPrice, UnitsInStock, UnitsInStock*UnitPrice AS TotalAccount FROM dbo.Products
--16
SELECT TOP 5 * FROM dbo.Customers
WHERE City LIKE 'M%'
--17
SELECT TOP 2 EmployeeID, LastName+FirstName AS EmployeeName, YEAR(GETDATE())-YEAR(BirthDate) AS Age FROM dbo.Employees
ORDER BY Age DESC
--18
SELECT * FROM dbo.Products
WHERE UnitsInStock < 5
--19
SELECT OrderID, ProductID, Quantity, UnitPrice, Discount, Quantity*UnitPrice - Discount*0,2 AS ToTal FROM dbo.[Order Details]
--20
SELECT * FROM dbo.Employees
WHERE City NOT IN('London','Redmond')