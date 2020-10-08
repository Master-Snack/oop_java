--TUẦN 9:
--BÀI TẬP 1: LỆNH INSERT
--1.Xóa hết các dữ liệu đang có trong các Table của cơ sở dữ liệu QLBH bằng lệnh Delete. 
delete from nhomsanpham
delete from ct_hoadon
delete from hoadon
delete from khachhang
delete from nhacungcap
delete from sanpham
--Trong trường hợp nào thì không xóa được dữ liệu bảng SanPham khi chưa xóa dữ liệu bảng con của SanPham? 
--
--Nếu bạn muốn xóa bất kỳ Bảng cha thì xóa luôn các bảng quan hệ thì bạn phải làm gì? Bạn thực hiện một ví dụ minh họa
--2.Dùng lệnh Insert thêm vào mỗi bảng của CSDL QLBH 5 record với nội dung do sinh viên tự nghĩ. 
insert Nhacungcap values (1,'Cong ty trach nhiem phuong nam','1 Le loi, phuong 4, go vap','083843456','32343434','namphuong@yahoo.com')
insert Nhacungcap values (2,'Cong ty trach nhiem ngoc Lan','12 Cao Ba Quat, Quan 1, Tp. HCM', '08234676','234453434','ngoclan@gmail.com')
insert Nhacungcap values (3,'Cong ty trach nhiem phuong bac','1 Le loi, phuong 4, go vap','083843456','32343434','namphuong@yahoo.com')
insert Nhacungcap values (4,'Cong ty trach nhiem ngoc diep','12 Cao Ba Quat, Quan 1, Tp. HCM', '08234676','234453434','ngoclan@gmail.com')
insert Nhacungcap values (5,'Cong ty trach nhiem phuong tay','1 Le loi, phuong 4, go vap','083843456','32343434','namphuong@yahoo.com')
insert Nhacungcap values (6,'Cong ty trach nhiem ngoc bich','12 Cao Ba Quat, Quan 1, Tp. HCM', '08234676','234453434','ngoclan@gmail.com')
select * from nhacungcap

insert nhomsanpham values (1,'Dien tu')
insert nhomsanpham values (2,'Gia Dung')
insert nhomsanpham values (3,'Dung cu gd')
insert nhomsanpham values (4,'Do dung ca nhan')
insert nhomsanpham values (5,'Cac mh khac')
select * from nhomsanpham

insert sanpham ([masp],[tensp],[donvitinh],[giagoc],[slton],[manhom],[mancc],mota)
values (1,'Ban Phim','cai',1000.0000,50,1,1,'Ban Phim 101 phim')

insert sanpham ([masp],[tensp],[donvitinh],[giagoc],[slton],[manhom],[mancc],mota)
values (2,'Chuot','cai',800.0000,150,1,1,'Chuot khong day')

insert sanpham ([masp],[tensp],[donvitinh],[giagoc],[slton],[manhom],[mancc],mota)
values (3,'CPU','cai',3000.0000,200,1,1,'CPU')

insert sanpham ([masp],[tensp],[donvitinh],[giagoc],[slton],[manhom],[mancc],mota)
values (4,'USB','cai',500.0000,100,1,1,'8GB')

insert sanpham ([masp],[tensp],[donvitinh],[giagoc],[slton],[manhom],[mancc],mota)
values (5,'Lo vi song','cai',10000000.0000,20,3,2,null)
select * from sanpham

insert khachhang values (1, 'Nguyen Thi Huyen Trang', 'vl', '12, NVB', '0136234', '3214234', 'huyentrang9917@gmail.com', 20)
insert khachhang values (2, 'Nguyen Van A', 'vl', '12, NVB', '0136234', '3214234', 'huyentrang9917@gmail.com', 20)
insert khachhang values (3, 'Nguyen Thi Huyen Tram', 'vl', '12, NVB', '0136234', '3214234', 'huyentrang9917@gmail.com', 20)
insert khachhang values (4, 'Pham Tan Dat', 'vl', '12, NVB', '0136234', '3214234', 'huyentrang9917@gmail.com', 20)
insert khachhang values (5, 'Nguyen Quoc Quy', 'vl', '12, NVB', '0136234', '3214234', 'huyentrang9917@gmail.com', 20)
select * from khachhang

set dateformat dmy
insert hoadon values (1, GETDATE(), '19-04-2019', 'Ha tinh', 1, 'n')
insert hoadon values (2, GETDATE(), '19-04-2019', 'Ha tinh', 2, 'n')
insert hoadon values (3, GETDATE(), '19-04-2019', 'Ha tinh', 3, 'n')
insert hoadon values (4, GETDATE(), '19-04-2019', 'Ha tinh', 4, 'n')
insert hoadon values (5, GETDATE(), '19-04-2019', 'Ha tinh', 5, 'n')
select * from hoadon

insert ct_hoadon values (1, 2, 20,100.500, 20)
insert ct_hoadon values (2, 3, 20,100.500, 20)
insert ct_hoadon values (3, 5, 20,100.500, 20)
insert ct_hoadon values (4, 4, 20,100.500, 20)
insert ct_hoadon values (5, 6, 20,100.500, 20)
select * from ct_hoadon

--3.Dùng câu lệnh INSERT … SELECT với các cột chọn cần thiết để đưa (nhớ kiểm tra kết quả sau mỗi lần thực hiện):
--	Các khách hàng có trong bảng Customers trong NorthWind vào bảng KhachHang trong QLBH.
insert khachhang([makh],[tenkh],[diachi], [phone], [sofax] )
select [CustomerID],[CompanyName],[Address], [Phone],  [Fax] from [Northwind].[dbo].[Customers]
select * from khachhang

--	Các sản phẩm có SupplierID từ 4 đến 29 ở bảng Products trong CSDL NorthWind vào bảng Sanpham trong QLBH.
--insert nhacungcap([mancc], [tenncc],[diachi], [phone],[sofax])
--select [SupplierID],[CompanyName], [Address], [Phone] , [Fax] 
--from [Northwind].[dbo].[Suppliers]
--select * from nhacungcap

insert sanpham([masp], [tensp])
select [ProductID],[ProductName]
from [Northwind].[dbo].[Products]
where SupplierID>=4 and SupplierID<=29
select * from sanpham

--	Danh sách tất cả các hoá đơn có OrderID nằm trong khoảng 10248 đến 10350 trong bảng Orders trong Northwind vào bảng HoaDon, các hoá đơn này được xem là hoá đơn xuất - tức LoaiHD là ‘X’
--alter table hoadon
--add constraint ck_ngaylhd check (ngaylaphd>=getdate())

insert hoadon(mahd, makh, loaihd)
select [OrderID], [CustomerID], 'x'
from [Northwind].[dbo].[Orders]
where OrderID>10248 and OrderID<10350
select * from hoadon

--	Danh sách tất cả các hoá đơn có OrderID nằm trong khoảng 10351 đến 10446 trong bảng Orders trong Northwind vào bảng HoaDon, các hoá đơn này được xem là hoá đơn nhập - tức LoaiHD là ‘N’
insert hoadon(mahd, makh, noichuyen, loaihd)
select [OrderID], [CustomerID], [ShipAddress], 'n'
from [Northwind].[dbo].[Orders]
where OrderID>10351 and OrderID<10446
select * from hoadon

--	Danh sách tất cả các chi tiết hoá đơn có OderID nằm trong khoảng 10248 đến 10270 trong bảng Order Detail trong NorthWind vào bảng CT_HoaDon.
insert ct_hoadon(mahd, masp, soluong, dongia, chietkhau)
select [OrderID],[ProductID] ,[Quantity] ,[UnitPrice], convert(money,[Discount])
from [Northwind].[dbo].[Order Details]
where OrderID>10248 and OrderID<10270
select * from ct_hoadon
----Chú ý: các ràng buộc khóa chính, khóa ngoại và các ràng buộc khác. Chỉ lấy các cột tương ứng với các bảng trong CSDL QLBH

--BÀI TẬP 2: LỆNH UPDATE
--1.Cập nhật đơn giá bán 100000 cho mã sản phẩm có tên bắt đầu bằng chữ T
UPDATE sanpham
set giagoc=100000
where tensp like 'T%'

--2.Cập nhật số lượng tồn = 50% số lượng tồn hiện có cho những sản phẩm có đơn vị tính có chữ box 
UPDATE sanpham
set slton = slton*0.5
where donvitinh like '%box%'

--3.Cập nhật mã nhà cung cấp là 1 trong bảng NHACUNGCAP  thành 100? Bạn có cập nhật được hay không?. Vì sao?. 
UPDATE nhacungcap
set mancc = 100
where mancc = 1
--Không thực hiện được vì mancc là FK, nó là mối gắn kết giữa tbl.nhacungcap và tbl.sanpham

--4.Tăng điểm tích lũy lên 100 cho những khách hàng mua hàng trong tháng 7 năm 1997
UPDATE khachhang
set diemtl = diemtl + 100
where exists (select * from hoadon where Month([ngaylaphd])=7 and year([ngaylaphd])=1997)

--5.Giảm 10% đơn giá bán cho những sản phẩm có số lượng tồn <10. 
UPDATE sanpham
set [giagoc] = [giagoc] - [giagoc]*0.1
where [slton] < 10
select * from sanpham

--6.Cập nhật giá bán trong bảng CT_HoaDon bằng với đơn giá mua trong bảng 
--SanPham của các sản phẩm do nhà cung cấp có mã là 4 hay 7.

--BÀI TẬP 3: LỆNH DELETE
--Lưu ý, việc xóa dữ liệu là công việc cần thận trọng, nên chúng ta 
--ít thao tác trên CSDL với lệnh DELETE, trừ khi loại bỏ dữ liệu tạm.
-- Nên phần này yêu cầu chúng ta phải sao chép dữ liệu trước khi thực hiện 
--các công việc sau:
--1.	Xóa các hóa đơn được lập trong tháng 7 năm 1996. Bạn có thực hiện được không? Vì sao? 
--###Không vì tbl.CT_Hoadon có dùng FK là orderID là PK của tbl.HoaDon
--2.	Xóa các hóa đơn của các khách hàng có loại là VL mua hàng trong năm 1996.
DELETE from hoadon
--where
--3.	Xóa các sản phẩm chưa bán được trong năm 1996. 
--4.	Xóa các khách hàng vãng lai. Lưu ý khi xóa xong thì phải xóa luôn các hóa đơn và các chi tiết của các hóa đơn này trong bảng HoaDon và bảng CTHoaDon
--5.	Tạo bảng HoaDon797 chứa các hóa đơn được lập trong tháng 7 năm 1997. Sau đó xóa toàn bộ dữ liệu của bảng này bằng lệnh Truncate