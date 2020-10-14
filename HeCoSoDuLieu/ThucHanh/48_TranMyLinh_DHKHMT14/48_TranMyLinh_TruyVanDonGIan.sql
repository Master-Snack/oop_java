USE [Northwind]
SET DATEFORMAT DMY
--1. Liệt kê thông tin của tất cả các sản phẩm (Products)
--
SELECT * FROM [dbo].[Products]
--
--2. Liệt kê danh sách các customers. Thông tin bao gồm CustomerID, CompanyName, City, Phone.
--
SELECT [CustomerID], [CompanyName], [City], [Phone] FROM [dbo].[Customers]
--
--3. Liệt kê danh sách các products. Thông tin bao gồm ProductId, ProductName, UnitPrice.
--
SELECT [ProductID], [ProductName], [UnitPrice] FROM [dbo].[Products]
--
--4. Liệt kê danh sách các employees. Thông tin bao gồm EmployeeId, EmployeeName, Phone, Age.
--Trong đó EmployeeName được ghép từ LastName và FirstName; Age là tuổi được tính từ năm hiện hành (GetDate()) và năm của Birthdate.
--
SELECT [EmployeeID], EmployeeName = [FirstName] + ' ' + [LastName], [HomePhone], Age = YEAR(GETDATE())-YEAR([BirthDate]) FROM [dbo].[Employees]
--
--5. Liệt kê danh sách các Customers có ContactTitle bắt đầu bằng chữ O
--
SELECT * FROM [dbo].[Customers] WHERE [ContactTitle] LIKE 'O%'
--
--6. Danh sách các customers ở thành phố Paris.
--
SELECT * FROM [dbo].[Customers] WHERE [City] = 'Paris'
--
--7. Liệt kê danh sách Customers ở thành phố LonDon, Boise và Paris
--
SELECT * FROM  [dbo].[Customers] WHERE [City] = 'Paris' OR [City] = 'LonDon'
--
--8. Liệt kê danh sách Customers có tên bắt đầu bằng chữ V mà ở thành phố Lyon
--
SELECT * FROM [dbo].[Customers] WHERE [City] ='Lyon' AND [CompanyName] LIKE 'V%'
--
--9. Liệt kê danh sách các Customers không có số fax
--
SELECT * FROM [dbo].[Customers] WHERE [Fax] IS NULL
--
10.Liệt kê danh sách các Customers có số Fax
--
SELECT * FROM [dbo].[Customers] WHERE [Fax] IS NOT NULL
--
--11.Liệt kê danh sách employees có năm sinh <=1960.
SELECT * FROM [dbo].[Employees] WHERE YEAR([BirthDate]) <= 1960
--
--12.Liệt kê danh sách các products có từ ‘Boxes’ trong cột QuantityPerUnit.
--
SELECT * FROM [dbo].[Products] WHERE [QuantityPerUnit] LIKE '%Boxes%'
--
--13.Liệt kê danh sách các products có Unitprice lớn hớn 10 và nhỏ hơn 15.
--
SELECT * FROM [dbo].[Products] WHERE [UnitPrice] > 10 AND [UnitPrice] < 15
--
--14.Liệt kê danh sách các orders có OrderDate được lập trong tháng 9 năm 1996.
--
SELECT * FROM [dbo].[Orders] WHERE MONTH([OrderDate]) = '9' AND YEAR([OrderDate]) = '1996'
--
--15.Liệt kê danh sách các products ứng với tiền tồn vốn. Thông tin bao gồm ProductId, ProductName, Unitprice, UnitsInStock, TotalAccount.
--Trong đó TotalAccount= UnitsInStock * Unitprice.
--
SELECT [ProductID], [ProductName], [UnitPrice], [UnitsInStock], TotalAccount = ([UnitsInStock] * [UnitPrice]) FROM [dbo].[Products]
--
--16.Liệt kê danh sách 5 customers có city bắt đầu ‘M’.
--
SELECT * FROM [dbo].[Customers] WHERE [City] LIKE 'M%'
--
--17.Liệt kê danh sách 2 employees có tuổi lớn nhất. Thông tin bao gồm EmployeeID, EmployeeName, Age.
--Trong đó, EmployeeName được ghép từ LastName và FirstName; Age là năm hiện hành trừ năm sinh.
--
SELECT TOP 2 WITH TIES [EmployeeID], EmployeeName = [LastName] + ' ' + [FirstName], Age = YEAR(GETDATE())-YEAR([BirthDate])  FROM [dbo].[Employees] ORDER BY Age DESC
--
--18.Liệt kê danh sách các Products có số lượng tồn nhỏ hơn 5
--
SELECT * FROM [dbo].[Products] WHERE [UnitsInStock] < 5
--
--19.Liệt kê danh sách các Orders gồm OrderId, Productid, Quantity, Unitprice, Discount, ToTal = Quantity * unitPrice – 20%*Discount.
--
SELECT *, ToTal = [Quantity] * [UnitPrice] - 20/100*[Discount] FROM [dbo].[Order Details]
--
--20.Liệt kê danh sách các Employees không ở thành phố London và Redmond
--
SELECT * FROM [dbo].[Employees] WHERE [City] != 'London' AND  [City] != 'Redmond'
--