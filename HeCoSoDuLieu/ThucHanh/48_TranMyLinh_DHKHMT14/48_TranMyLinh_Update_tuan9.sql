--BÀI TẬP 2: LỆNH UPDATE
--1. Cập nhật đơn giá bán 100000 cho mã sản phẩm có tên bắt đầu bằng chữ T
--
UPDATE [dbo].[SanPham]
SET [GiaGoc] = '100000'
WHERE [TenSP] LIKE 'T%'
--
--2. Cập nhật số lượng tồn = 50% số lượng tồn hiện có cho những sản phẩm có
--đơn vị tính có chữ box
--
UPDATE [dbo].[SanPham]
SET [SLTon] = ([SLTon]*1/2)
WHERE [DonViTinh] LIKE '%box%'
--
--3. Cập nhật mã nhà cung cấp là 1 trong bảng NHACUNGCAP thành 100? Bạn
--có cập nhật được hay không?. Vì sao?.
--
UPDATE [dbo].[NhaCungCap]
SET [MaNCC] = '100'
WHERE [MaNCC] = '1'
--không vì mã mã nhà cung cấp là khóa ngoại của bảng SanPham. cần phải xóa dữ liệu có mã nhà cung cấp =1 của bảng SanPham trước khi cập nhật.
--
--4. Tăng điểm tích lũy lên 100 cho những khách hàng mua hàng trong tháng 7 năm 1997
--
SET DATEFORMAT DMY
UPDATE [dbo].[KhachHang]
SET [DiemTL] = ([DiemTL] + 100)
WHERE [MaKH] IN (SELECT [MaKH] FROM [dbo].[HoaDon] WHERE MONTH([NgayLapHD]) = '7' AND YEAR([NgayLapHD]) = '1997')
--
--5. Giảm 10% đơn giá bán cho những sản phẩm có số lượng tồn <10.
--
UPDATE [dbo].[SanPham]
SET [GiaGoc] = ([GiaGoc]*9/10)
WHERE [SLTon] < 10
--
--6. Cập nhật giá bán trong bảng CT_HoaDon bằng với đơn giá mua trong bảng
--SanPham của các sản phẩm do nhà cung cấp có mã là 4 hay 7.
UPDATE [dbo].[CT_HoaDon]
SET [dbo].[CT_HoaDon].[DonGia] = [dbo].[SanPham].[GiaGoc]
FROM [dbo].[CT_HoaDon] INNER JOIN [dbo].[SanPham]
ON [dbo].[CT_HoaDon].[MaSP] = [dbo].[SanPham].[MaSP]
WHERE [dbo].[SanPham].[MaNCC] IN ('4', '7')
