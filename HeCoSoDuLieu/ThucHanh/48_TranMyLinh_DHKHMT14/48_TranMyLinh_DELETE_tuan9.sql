USE QLBH
--1. Xóa các hóa đơn được lập trong tháng 7 năm 1996. Bạn có thực hiện được không? Vì sao?
--
DELETE FROM [dbo].[HoaDon]
WHERE MONTH([NgayLapHD]) = '7' AND YEAR([NgayLapHD]) = '1996'
--không xóa được vì cột mã hóa đơn là ở bảng CT_HoaDon là khóa ngoại tham chiếu đến bảng HoaDon.
--
--2. Xóa các hóa đơn của các khách hàng có loại là VL mua hàng trong năm 1996.
--
SET DATEFORMAT DMY
DELETE FROM [dbo].[CT_HoaDon]
WHERE [MaHD] IN (SELECT [MaHD] FROM [dbo].[HoaDon] HD JOIN [dbo].[KhachHang] KH ON HD.[MaKH] = KH.[MaKH]
												WHERE [LoaiKH] = 'VL' AND YEAR(HD.[NgayLapHD]) = '1996')
--
--3. Xóa các sản phẩm chưa bán được trong năm 1996.
DELETE FROM [dbo].[SanPham]
WHERE [MaSP] NOT IN ( SELECT SP.[MaSP] FROM [dbo].[SanPham] SP JOIN [dbo].[CT_HoaDon] CTHD ON SP.[MaSP] = CTHD.[MaSP] JOIN [dbo].[HoaDon] HD ON  HD.[MaHD] = CTHD.[MaHD]
						WHERE YEAR(HD.[NgayLapHD]) = '1996')
--4. Xóa các khách hàng vãng lai. Lưu ý khi xóa xong thì phải xóa luôn các hóa
--đơn và các chi tiết của các hóa đơn này trong bảng HoaDon và bảng CTHoaDon
DELETE FROM [dbo].[KhachHang]
WHERE [LoaiKH] = 'VL'
DELETE FROM [dbo].[HoaDon]
WHERE [MaKH] NOT IN (SELECT [MaKH] FROM [dbo].[KhachHang])
DELETE FROM [dbo].[CT_HoaDon]
WHERE [MaHD] NOT IN (SELECT [MaHD] FROM [dbo].[HoaDon])
--5. Tạo bảng HoaDon797 chứa các hóa đơn được lập trong tháng 7 năm 1997.
--Sau đó xóa toàn bộ dữ liệu của bảng này bằng lệnh Truncate
CREATE TABLE HoaDon797(
	MaHD INT NOT NULL,
	NgayLapHD DATETIME,
	NgayGiao DATETIME,
	NoiChuyen NVARCHAR(60) NOT NULL,
	MaKH NCHAR(5)
	LoaiHD CHAR(1) CHECK (LoaiHD = 'N' OR LoaiHD = 'X' OR LoaiHD = 'C' OR LoaiHD = 'T'))\

INSERT HoaDon797([MaHD],[NgayLapHD],[NgayGiao],[NoiChuyen],[MaKH],[LoaiHD]) SELECT  [MaHD],[NgayLapHD],[NgayGiao],[NoiChuyen],[MaKH],[LoaiHD] FROM [dbo].[HoaDon]
WHERE MONTH([NgayLapHD])='7' AND YEAR([NgayLapHD])='1997'

TRUNCATE TABLE [dbo].[HoaDon797]

