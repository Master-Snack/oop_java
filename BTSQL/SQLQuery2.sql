-- Tên: Lê Văn Tiến
-- MSSV: 19430791
-- Sáng thứ 6 (25/9/2020) tiết 4-6

CREATE DATABASE QLBH
ON 
PRIMARY (NAME=QLBH_data1,
FILENAME='T:\QLBH_data1.mdf',
SIZE=10MB,
MAXSIZE=40MB,
FILEGROWTH=1MB)
LOG ON
(NAME=QLBH_Log,
FILENAME= 'T:\QLBH.ldf',
SIZE=6MB,
MAXSIZE=8MB,
FILEGROWTH=1MB)

-- MỞ CSDL QLBH
USE QLBH

-- xem lai thuoc tinh
SP_HELPDB

-- xem lai thuoc tinh của 1 csdl hiện hành
SP_HELPDB QLBH

-- kiểm tra không gian sử dụng của csdl
sp_spaceused

-- 
sp_helpfile



ALTRE DATABASE QLBH
	ADD FILE DULIEUQLBH TO FILEGROUP QLBH
