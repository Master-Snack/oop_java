delete from KhachHang
--KhachHang TB
Insert KhachHang Values (1,'Nguyen Thi Huyen Trang', 'VIP', '12, NVB', '017263', '124234', 'HuyenTrang9917@gmail.com', 20)
Insert KhachHang Values (2,'Nguyễn Nhật Lý', 'TV', '12, NVB', '017263', '124234', 'Nhatly608@gmail.com', 20

--NhaCungCcap TB
Insert NhaCungCap Values (12, 'Trump', '12NVB', '023624', '2424', 'abc@gmail.com')
Insert NhaCungCap Values (13, 'Bill', '12NVB', '023624', '2424', 'cbs@gmail.com')

--NhomSanPham TB
Insert NhomSanPham Values (123, 'Dien Tu')
Insert NhomSanPham Values (124, 'Thoi Trang')

--SanPham TB
Insert SanPham Values (34, 'May Tinh', 12, '', 123, 'Cai', 700000, 20)
Insert SanPham Values (35, 'Ban Phim', 13, '', 123, 'Cai', 129000, 30)
Insert SanPham Values (36, 'Tui Xach', 12, '', 124, 'cai', 1200000, 10

set dateformat dmy
--set dateformat ymd
--HoaDon TB
Insert HoaDon Values (1234, '12-02-2018', '13-02-2018', '12NVB', 1, 'n')
Insert HoaDon Values (1235, '16-02-2019', '17-02-2019', '12NVB', 2,'c')
Insert HoaDon Values (1236, '12-10-2017', '15-10-2017', 'HS-HT', 1,'t')

--CT_HoaDon TB
Insert CT_HoaDon Values (1234, 34, 2, 2300000, 10)
Insert CT_HoaDon Values (1235, 35, 5, 1000000, 20)
Insert CT_HoaDon Values (1236, 36, 7, 2000000, 15)
Insert CT_HoaDon Values (1237, 37, 9, 3000000, 20)
Insert CT_HoaDon Values (1238, 38, 11, 4000000, 25)
Insert CT_HoaDon Values (1239, 39, 13, 5000000, 23)
Insert CT_HoaDon Values (1240, 40, 15, 6000000, 24)

select * from Ct_HoaDon 
select * from KhachHang
select * from NhaCungCap
select * from NhomsanPham
select * from SanPham 
select * from HoaDon
--cau 3.a
select * from SanPham where masp=34
Update sanpham set giagoc=giagoc*1.05 where masp=34
--cau 3.b
select * from SanPham where maNhom=123 and maNCC=12
Update sanpham set slton=100 where maNhom=123 and maNCC=12
--cau 3.d
select * from KhachHang where LoaiKH<>'VL'
Update KhachHang set diemTL=DiemTl+50 where  LoaiKH<>'VL'
--cau 3.e
select * from sanPham where tenSP like '%u%'
Update sanPham set giagoc=giagoc*1.02 where tenSP like '%u%'

--cau 4.a
select * from sanPham where SLTon<2
Delete from SanPham Where SLTon<2

--cau 4.b
select * from hoaDon where maKH in (select maKH from KhachHang where loaiKh='VL')
Delete from HoaDon Where maKH in (select maKH from KhachHang where loaiKh='VL')

--cau 4.c
select * from KhachHang Where LoaiKH = 'VIP' and DiemTL =0
Delete from KhachHang Where LoaiKH = 'VIP' and DiemTL =0


