--3. Dùng câu lệnh INSERT … SELECT với các cột chọn cần thiết để đưa (nhớ kiểm tra kết quả sau mỗi lần thực hiện):
--Các khách hàng có trong bảng Customers trong NorthWind vào bảng KhachHang trong QLBH.
--
SELECT * FROM [QLBH].[dbo].[KhachHang]
INSERT [QLBH].[dbo].[KhachHang]([MaKH],[TenKH],[DiaChi],[Phone],[SoFax]) SELECT [CustomerID],[CompanyName],[Address],[Phone],[Fax] FROM [dbo].[Customers]
--
--Các sản phẩm có SupplierID từ 4 đến 29 ở bảng Products trong CSDL NorthWind vào bảng Sanpham trong QLBH.
--
SELECT * FROM [QLBH].[dbo].[SanPham]
SELECT * FROM [QLBH].[dbo].NhaCungCap
--
INSERT [QLBH].[dbo].[NhaCungCap]([MaNCC],[TenNCC],[DiaChi],[Phone],[SoFax]) SELECT [SupplierID],[CompanyName],[Address],[Phone],[Fax] FROM [dbo].[Suppliers]
--
INSERT [QLBH].[dbo].[NhomSanPham]([MaNhom],[TenNhom]) SELECT [CategoryID],[CategoryName] FROM [dbo].[Categories]
--
INSERT [QLBH].[dbo].[SanPham]([MaSP],[TenSP],[MaNCC],[MaNhom],[DonViTinh],[GiaGoc],[SLTon]) SELECT [ProductID],[ProductName],[SupplierID],[CategoryID],[QuantityPerUnit],[UnitPrice],[UnitsInStock] FROM [dbo].[Products]
--
--Danh sách tất cả các hoá đơn có OrderID nằm trong khoảng 10248 đến 10350 trong bảng Orders trong Northwind vào bảng HoaDon,
--các hoá đơn này được xem là hoá đơn xuất - tức LoaiHD là ‘X’
--
SELECT * FROM [QLBH].[dbo].[HoaDon]
INSERT [QLBH].[dbo].[HoaDon]([MaHD],[NgayLapHD],[NgayGiao],[NoiChuyen],[MaKH],[LoaiHD]) SELECT [OrderID],[OrderDate],[ShippedDate],[ShipAddress],[CustomerID],'X' FROM [dbo].[Orders]
WHERE [OrderID] BETWEEN '10248' AND '10350'
--
--Danh sách tất cả các hoá đơn có OrderID nằm trong khoảng 10351 đến 10446 trong bảng Orders trong Northwind vào bảng HoaDon,
--các hoá đơn này được xem là hoá đơn nhập - tức LoaiHD là ‘N’
--
INSERT [QLBH].[dbo].[HoaDon]([MaHD],[NgayLapHD],[NgayGiao],[NoiChuyen],[MaKH],[LoaiHD]) SELECT  [OrderID],[OrderDate],[ShippedDate],[ShipAddress],[CustomerID],'N' FROM [dbo].[Orders]
WHERE [OrderID] BETWEEN '10351' AND '10446'
--
--Danh sách tất cả các chi tiết hoá đơn có OderID nằm trong khoảng 10248 đến 10270 trong bảng Order Detail trong NorthWind vào bảng CT_HoaDon
--
SELECT * FROM [QLBH].[dbo].[CT_HoaDon]
INSERT [QLBH].[dbo].[CT_HoaDon]([MaHD],[MaSP],[SoLuong],[DonGia],[ChietKhau]) SELECT [OrderID],[ProductID],[Quantity],[UnitPrice],[Discount] FROM [dbo].[Order Details]
WHERE [OrderID] BETWEEN '10248' AND '10270'
--
