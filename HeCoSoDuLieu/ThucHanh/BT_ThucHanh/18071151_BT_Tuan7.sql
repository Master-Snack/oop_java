----Cau 1-- Danh sách các orders ứng với tổng tiền của từng hóa đơn. 
--Thông tin bao gồm OrdersId, OrderDate, TotalAccount. 
--Trong đó TotalAccount là Sum của Quantity * Unitprice, kết nhóm theo OrderId.
select o.OrderID, o.OrderDate,'$' + 
convert (char,sum(od.UnitPrice*od.Quantity*(1-od.Discount))) as 'TotalAccount'
from dbo.[Order Details] od join dbo.Orders o on o.OrderID=od.OrderID
group by o.OrderID,o.OrderDate
--Hoặc--
select o.OrderID, OrderDate, '$' +  
convert(char,SUM(Quantity*UnitPrice*(1-Discount)) )
from [Order Details] d 
join Orders o on o.OrderID=d.OrderID
group by o.OrderID,OrderDate

--Cau 2-- Danh sách các orders ứng với tổng tiền của từng hóa đơn có Shipcity là ‘Madrid’.
--Thông tin bao gồm OrdersId, OrderDate, TotalAccount. 
--Trong đó TotalAccount là Sum của Quantity * Unitprice, kết nhóm theo OrderId.
select o.OrderID,o.OrderDate,
SUM(od.Quantity*od.UnitPrice*(1- od.Discount)) as 'TotalAccount'
from dbo.[Order Details] od join dbo.Orders o on o.OrderID=od.OrderID
where o.ShipCity like ('%Madrid%')
group by o.OrderID,o.OrderDate
--Hoặc--
select o.OrderID, OrderDate, '$' +  
convert(char,SUM(Quantity*UnitPrice*(1-Discount)) )
from [Order Details] d join Orders o on o.OrderID=d.OrderID
where ShipCity='Madrid'
group by o.OrderID,OrderDate

--Cau 3-- Danh sách các products có tổng số lượng lập hóa đơn lớn nhất.
select top 1 p.ProductID, p.ProductName
from dbo.[Order Details] od join dbo.Products p on p.ProductID=od.ProductID
GROUP by p.ProductID, p.ProductName
order by COUNT(*) desc
--Hoặc--
select top 2 with ties p.ProductID, COUNT(OrderID) as SoHDlap
from Products p join [Order Details] o on p.ProductID=o.ProductID
group by p.ProductID
order by  SoHDlap desc

--Cau 4-- Cho biết mỗi customers đã lập bao nhiêu lượt hóa đơn bao. 
--Thông tin gồm CustomerID, CompanyName, CountOfOrder. 
--Trong đó CountOfOrder (tổng số hóa đơn) được đếm (Count) theo từng Customers.
select c.CustomerID,c.CompanyName,COUNT(*) as 'CountOfOrder'
from dbo.Orders o join dbo.Customers c on c.CustomerID = o.CustomerID
group by c.CustomerID,c.CompanyName
--Hoặc--
select c.CustomerID,c.CompanyName,COUNT(*) as 'So_Lan_Lap'
from Orders o join Customers c on c.CustomerID = o.CustomerID
group by c.CustomerID,c.CompanyName
order by COUNT(*) desc

--Cau 5-- Cho biết mỗi Employee đã lập được bao nhiêu hóa đơn, ứng với tổng tiền.
select e.EmployeeID,'$' + 
convert(char,sum(UnitPrice*Quantity*(1-Discount))) as 'Tong_Tien',
COUNT(*) as 'So_Hoa_Don'
from Employees e join Orders o on e.EmployeeID=o.EmployeeID 
join [Order Details] od on od.OrderID =o.OrderID
group by e.EmployeeID

--Cau 6-- Cho biết những Customers chưa từng lập hóa đơn.
---select * from Customers c inner join Orders o on o.CustomerID=c.CustomerID --830
select c.CustomerID,c.CompanyName,COUNT(*) as 'CountOfOrder'
from dbo.Orders o join dbo.Customers c on c.CustomerID = o.CustomerID
group by c.CustomerID,c.CompanyName
having COUNT(*)=0
--Hoặc--
select c.CustomerID, o.OrderID from Customers c left join Orders o on o.CustomerID=c.CustomerID
where  OrderID is null --832
---select * from Customers c right join Orders o on o.CustomerID=c.CustomerID --830
-------------
--select c.CustomerID,c.CompanyName,COUNT(*) as 'So_Hoa_Don'
--from Orders o join Customers c on c.CustomerID = o.CustomerID
--group by c.CustomerID,c.CompanyName
--having COUNT(*)=0

--Cau 7-- Danh sách các customer ứng với tổng tiền các hoá đơn được lập từ 31/12/1996 đến 1/1/1998.
select c.CustomerID, c.CompanyName, '$' + 
convert(char,sum(od.UnitPrice*od.Quantity*(1-od.Discount))) as 'Tong_Tien'
from Customers c join Orders o on o.CustomerID=c.CustomerID 
join [Order Details] od on od.OrderID=o.OrderID
where o.OrderDate between '12/31/1996' and '1/1/1998'
group by  c.CustomerID, c.CompanyName

--Cau 8-- Danh sách các customer ứng với tổng tiền các hoá đơn, 
--mà các hóa đơn được lập từ 31/12/1996 đến 1/1/1998 và tổng tiền các hóa đơn >20000.
select c.CustomerID, c.CompanyName, '$' + 
convert(char,sum(od.UnitPrice*od.Quantity*(1-od.Discount))) as 'Tong_Tien'
from dbo.Customers c join dbo.Orders o on o.CustomerID=c.CustomerID 
join dbo.[Order Details] od on od.OrderID=o.OrderID
where o.OrderDate between '12/31/1996' and '1/1/1998'
group by  c.CustomerID, c.CompanyName
having sum(od.UnitPrice*od.Quantity*(1-od.Discount)) > 20000

--select CustomerID, Tong_Tien=SUM(Quantity*UnitPrice*(1-Discount))
--from orders o join [Order Details] d on o.OrderID=d.OrderID
--where OrderDate between '12/31/1996' and '1/1/1998'
--group by CustomerID
--having SUM(Quantity*UnitPrice*(1-Discount))>20000

--Cau 9-- Danh sách các customer ứng với tổng số hoá đơn, tổng tiền các hoá đơn, 
--mà các hóa đơn được lập từ 31/12/1996 đến 1/1/1998 và tổng tiền các hóa đơn >20000. 
--Thông tin được sắp xếp theo CustomerID, cùng mã thì sắp xếp theo tổng tiền giảm dần.
select c.CustomerID, c.CompanyName,COUNT(*) as CountOfOrder, '$' + 
convert(char,sum(od.UnitPrice*od.Quantity*(1-od.Discount))) as 'Tong_Tien'
from dbo.Customers c join dbo.Orders o on o.CustomerID=c.CustomerID 
join dbo.[Order Details] od on od.OrderID=o.OrderID
where o.OrderDate between '12/31/1996' and '1/1/1998'
group by  c.CustomerID, c.CompanyName
having sum(od.UnitPrice*od.Quantity*(1-od.Discount)) > 2000
order by c.CustomerID, sum(od.UnitPrice*od.Quantity*(1-od.Discount)) desc

--Cau 10-- Danh sách các Category có tổng số lượng tồn (UnitsInStock) lớn hơn 300, 
--đơn giá trung bình nhỏ hơn 25. 
--Thông tin kết quả bao gồm CategoryID, CategoryName, Total_UnitsInStock, Average_Unitprice.
select c.CategoryID,CategoryName,SUM(UnitsInStock) as So_Luong_Ton,
									AVG(UnitPrice) as Don_Gia_Trung_Binh
from dbo.Categories c join Products p on p.CategoryID = c.CategoryID
group by c.CategoryID,CategoryName
having SUM(UnitsInStock)>300 and AVG(UnitPrice)<25
--Hoặc--
select c.CategoryID,CategoryName,UnitsInStock,UnitPrice
from dbo.Categories c join Products p on p.CategoryID = c.CategoryID
order by c.CategoryID,CategoryName
compute sum(UnitsInStock),avg(UnitPrice) by c.CategoryID

--Cau 13-- Danh sách các Customer ứng với tổng tiền của các hóa đơn ở từng tháng. 
--Thông tin bao gồm CustomerID, CompanyName, Month_Year, Total. 
--Trong đó Month_year là tháng và năm lập hóa đơn, Total là tổng của Unitprice* Quantity, 
--có thống kế tổng của total theo từng Customer và Month_Year . (có dùng COMPUTE)
select c.CustomerID,CompanyName,
CONVERT(char(2),MONTH(OrderDate))+'/'+CONVERT(char(4),year(OrderDate)) 
as Thang_Nam,sum(UnitPrice*Quantity*(1-Discount)) as Tong_Tien
from dbo.Customers c join dbo.Orders o on o.CustomerID=c.CustomerID 
join dbo.[Order Details] d on d.OrderID=o.OrderID
group by c.CustomerID,CompanyName,
CONVERT(char(2),MONTH(OrderDate))+'/'+CONVERT(char(4),year(OrderDate))
order by c.CustomerID,CONVERT(char(2),MONTH(OrderDate))+'/'+CONVERT(char(4),year(OrderDate))

--Cau 14-- Cho biết Employees nào bán được nhiều tiền nhất trong 7 của năm 1997
select top 1 e.EmployeeID,hotenNV=LastName+' '+FirstName,
SUM(UnitPrice*Quantity*(1-Discount)) as tongtien
from dbo.Employees e join dbo.Orders o on o.EmployeeID=e.EmployeeID 
join dbo.[Order Details] d on d.OrderID=o.OrderID
where OrderDate between '1/1/1997' and '12/31/1997'
group by e.EmployeeID,FirstName,LastName
order by SUM(UnitPrice*Quantity*(1-Discount)) desc
--Hoặc--
select e.EmployeeID,hotenNV=LastName+' '+FirstName,SUM(UnitPrice*Quantity*(1-Discount)) as tongtien
from dbo.Employees e join dbo.Orders o on o.EmployeeID=e.EmployeeID 
join dbo.[Order Details] d on d.OrderID=o.OrderID
where OrderDate between '1/1/1997' and '12/31/1997'
group by e.EmployeeID,FirstName,LastName
having SUM(UnitPrice*Quantity*(1-Discount)) >= all(select SUM(UnitPrice*Quantity*(1-Discount))
from dbo.[Order Details] dd join dbo.Orders oo on oo.OrderID=dd.OrderID
where OrderDate between '1/1/1997' and '12/31/1997'
group by EmployeeID)
-- cau 15:
select c.[CustomerID], [CompanyName], count(od.orderID) as Cout_order
from ([dbo].[Customers] c inner join [dbo].[Orders] o on c.CustomerID = o.CustomerID)
		inner join [dbo].[Order Details] od on od.OrderID = o.OrderID
where YEAR(OrderDate) = 1997
group by c.[CustomerID], [CompanyName]
having count(od.orderID)  > 10
order by Cout_order desc
