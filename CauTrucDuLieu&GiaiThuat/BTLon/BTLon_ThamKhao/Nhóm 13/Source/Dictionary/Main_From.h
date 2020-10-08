#pragma once
#include "Main_Header.h"


class Main_From
{
private:
	wstring* savepath;//* path
	List_WordMean* List_pipe, * List_tu_duoc_them;
	Database* Db;


	Label DeXuat[4], SearchBox, title1, title2, BanDich, MuiTen, Lb_ClearSearchBox, Lb1_ClearSearchBox, Lb_Refresh, Lb1_Refresh, Lb_Options, Lb1_Options, Lb_ADD, Lb1_ADD, Lb_RemoveTudangtra, Lb1_RemoveTudangtra, Lb_LuuThayDoi,
		Lb1_LuuThayDoi;
	wstring word_search;
	wstring* Mean;
	int Vitri_Muiten = 0;

public:
	void operator()()
	{
		Run_Load_Set();
		Run_Mainform();
	}
public:
	Main_From();
	~Main_From();
private:
	void Load()
	{
		//path_ = new wstring;  *path = ;
		savepath = new wstring;
		*savepath = L"P:/data/av.dictionary";

		List_pipe = new List_WordMean;
		List_tu_duoc_them = new List_WordMean;

		Db = new Database;
		Mean = NULL;
	}

	void ThemTuMoi()
	{
		system("cls");
		wcout << L"\nGõ    /end  để kết thúc việc thêm từ\n\n-----------NHẤN PHÍM BẤT KỲ ĐỂ TIẾP TỤC-----------\n";
		_getch();
		system("cls");
		StdCursorInfo->dwSize = 10;
		StdCursorInfo->bVisible = true;
		SetConsoleCursorInfo(StdHandel, StdCursorInfo);
		List_tu_duoc_them->ShowAllItem();
		wstring word_themtu, mean_themtu;
		while (true)
		{
			wcout << L"\tItem: " << List_tu_duoc_them->Length + 1 << L"\n";
			wcout << L"\t\tWord: "; getline(wcin, word_themtu);
			if (word_themtu == L"/end") break;
			wcout << L"\t\tMean: "; getline(wcin, mean_themtu);
			if (mean_themtu == L"/end") break;

			List_tu_duoc_them->ADD(word_themtu, mean_themtu);
			Db->ADD(word_themtu, mean_themtu);
		}
	}

	void Run_Load_Set()
	{	
		//thread t5(LoadFile, List_pipe, path);
		//wstring path_tam = L"I:/b/av.dictionary";
		//thread t1(LoadData, List_pipe, &path_tam);

		thread t1(LoadData, List_pipe);
		//thread t1(LoadData, List_pipe, &path_av_dictionary);
		thread t2(SetData, List_pipe, Db);
		t1.join();
		t2.join();
		List_pipe->~List_WordMean();
		delete List_pipe;
	}


	//======================================================================================================

	void Load_Mainform()
	{
		system("cls");
		StdCursorInfo->bVisible = false;
		SetConsoleCursorInfo(StdHandel, StdCursorInfo);
		title1.Location.X = 30;
		title1.Location.Y = 3;
		title1.Size = 13;
		title1.AutoSize = false;
		title1.Text = L"Tiếng Anh:";
		title1.BackgroundFontColor = Color.Green;

		title2.Location.X = title1.Location.X;
		title2.Location.Y = title1.Location.Y + 5;
		title2.Size = title1.Size;
		title2.AutoSize = title1.AutoSize;
		title2.Text = L"Tiếng Việt:";
		title2.BackgroundFontColor = Color.Red;
		

		SearchBox.AutoSize = false;
		SearchBox.Size = 40;
		SearchBox.BackgroundFontColor = Color.White + Light;
		SearchBox.FontColor = Color.Red + Light;
		SearchBox.Location.X = title1.Location.X + title1.Size +2;
		SearchBox.Location.Y = title1.Location.Y;
		

		for (int i = 0; i < 4; i++)
		{
			DeXuat[i].Location.X = SearchBox.Location.X;
			DeXuat[i].Location.Y = SearchBox.Location.Y + i + 1;
			DeXuat[i].FontColor = Color.Green + Light;
			DeXuat[i].Refresh();
		}

		BanDich.Location.X = SearchBox.Location.X;
		BanDich.Location.Y = title2.Location.Y;
		BanDich.FontColor = Color.Yellow + Light;
		//BanDich.BackgroundFontColor = Color.White;
		

		Vitri_Muiten = 0;
		MuiTen.Location.X = SearchBox.Location.X - 4;

		Lb_ClearSearchBox.Location.Y = title2.Location.Y + 2;
		Lb_ClearSearchBox.Location.X = title2.Location.X;
		Lb_ClearSearchBox.Text = L"[DELETE]";
		Lb_ClearSearchBox.FontColor = Color.Green + Light;
		Lb_ClearSearchBox.BackgroundFontColor = Color.Magenta;

		
		Lb1_ClearSearchBox.Location.Y = Lb_ClearSearchBox.Location.Y;
		Lb1_ClearSearchBox.Location.X = Lb_ClearSearchBox.Location.X + Lb_ClearSearchBox.Text.length();
		Lb1_ClearSearchBox.Text = L" : Làm sạch ô tìm kiếm";
		Lb1_ClearSearchBox.FontColor = Color.Cyan + Light;

		Lb_Refresh.Location.Y = Lb_ClearSearchBox.Location.Y + 2;
		Lb_Refresh.Location.X = Lb_ClearSearchBox.Location.X;
		Lb_Refresh.Text = L"[F1]";
		Lb_Refresh.FontColor = Color.Green + Light;
		Lb_Refresh.BackgroundFontColor = Color.Magenta;

		Lb1_Refresh.Location.Y = Lb_Refresh.Location.Y;
		Lb1_Refresh.Location.X = Lb1_ClearSearchBox.Location.X;
		Lb1_Refresh.Text = L" : Làm mới màn hình hiện tại";
		Lb1_Refresh.FontColor = Color.Cyan + Light;

		Lb_Options.Location.Y = Lb_Refresh.Location.Y + 2;
		Lb_Options.Location.X = Lb_Refresh.Location.X;
		Lb_Options.Text = L"[F2]";
		Lb_Options.FontColor = Color.Green + Light;
		Lb_Options.BackgroundFontColor = Color.Magenta;

		Lb1_Options.Location.Y = Lb_Options.Location.Y;
		Lb1_Options.Location.X = Lb1_ClearSearchBox.Location.X;
		Lb1_Options.Text = L" : Hiển thị menu cài đặt";
		Lb1_Options.FontColor = Color.Cyan + Light;

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		Lb_ADD.Location.Y = Lb_Options.Location.Y + 2;
		Lb_ADD.Location.X = Lb_Options.Location.X;
		Lb_ADD.Text = L"[F3]";
		Lb_ADD.FontColor = Color.Green + Light;
		Lb_ADD.BackgroundFontColor = Color.Magenta;

		Lb1_ADD.Location.Y = Lb_ADD.Location.Y;
		Lb1_ADD.Location.X = Lb1_ClearSearchBox.Location.X;
		Lb1_ADD.Text = L" : Thêm từ mới vào từ điển";
		Lb1_ADD.FontColor = Color.Cyan + Light;

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		Lb_RemoveTudangtra.Location.Y = Lb_ADD.Location.Y + 2;
		Lb_RemoveTudangtra.Location.X = Lb_ADD.Location.X;
		Lb_RemoveTudangtra.Text = L"[F4]";
		Lb_RemoveTudangtra.FontColor = Color.Green + Light;
		Lb_RemoveTudangtra.BackgroundFontColor = Color.Magenta;

		Lb1_RemoveTudangtra.Location.Y = Lb_RemoveTudangtra.Location.Y;
		Lb1_RemoveTudangtra.Location.X = Lb1_ClearSearchBox.Location.X;
		Lb1_RemoveTudangtra.Text = L" : Xóa từ đang tra khỏi từ điển";
		Lb1_RemoveTudangtra.FontColor = Color.Cyan + Light;

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		Lb_LuuThayDoi.Location.Y = Lb_RemoveTudangtra.Location.Y + 2;
		Lb_LuuThayDoi.Location.X = Lb_ADD.Location.X;
		Lb_LuuThayDoi.Text = L"[F5]";
		Lb_LuuThayDoi.FontColor = Color.Green + Light;
		Lb_LuuThayDoi.BackgroundFontColor = Color.Magenta;

		Lb1_LuuThayDoi.Location.Y = Lb_LuuThayDoi.Location.Y;
		Lb1_LuuThayDoi.Location.X = Lb1_ClearSearchBox.Location.X;
		Lb1_LuuThayDoi.Text = L" : Lưu lại các thay đổi";
		Lb1_LuuThayDoi.FontColor = Color.Cyan + Light;
		
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		title1.Refresh();

		title2.Refresh();

		BanDich.Refresh();

		Lb_ClearSearchBox.Refresh();
		Lb1_ClearSearchBox.Refresh();

		Lb_Refresh.Refresh();
		Lb1_Refresh.Refresh();

		Lb1_Options.Refresh();
		Lb_Options.Refresh();

		Lb1_ADD.Refresh();
		Lb_ADD.Refresh();

		Lb1_RemoveTudangtra.Refresh();
		Lb_RemoveTudangtra.Refresh();

		Lb_LuuThayDoi.Refresh();
		Lb1_LuuThayDoi.Refresh();

		SearchBox << L"Nhập từ cần dịch vào đây !";
	}

	void LamMoiManHinh()
	{
		StdCursorInfo->bVisible = false;
		SetConsoleCursorInfo(StdHandel, StdCursorInfo);
		system("cls");
		title1.Refresh();
		title2.Refresh();
		BanDich.Refresh();

		Lb_ClearSearchBox.Refresh();
		Lb1_ClearSearchBox.Refresh();
		Lb_Refresh.Refresh();
		Lb1_Refresh.Refresh();
		Lb1_Options.Refresh();
		Lb_Options.Refresh();
		Lb1_ADD.Refresh();
		Lb_ADD.Refresh();
		Lb1_RemoveTudangtra.Refresh();
		Lb_RemoveTudangtra.Refresh();
		Lb_LuuThayDoi.Refresh();
		Lb1_LuuThayDoi.Refresh();

		SearchBox << L"Nhập từ cần dịch vào đây !";
	}

	void MenuCaiDat()
	{
		Label menu_caidat, lb1, lb2, lb3, lb4;
		menu_caidat.Text = L"Cài đặt";
		menu_caidat.Location.X = 58;
		menu_caidat.Location.Y = 3;
		menu_caidat.FontColor = Color.Green;


		lb1.Text = L"Khoảng thời gian nhắc nhở";
		lb1.Location.X = 40;
		lb1.Location.Y = menu_caidat.Location.Y + 2;
		lb1.BackgroundFontColor = Color.White;
		lb1.FontColor = Color.Red;
		lb1.AutoSize = false;
		lb1.Size = 45;

		lb2.Text = L"Số lượng đề xuất";
		lb2.Location.X = lb1.Location.X;
		lb2.Location.Y = lb1.Location.Y + 2;
		lb2.BackgroundFontColor = lb1.BackgroundFontColor;
		lb2.FontColor = lb1.FontColor;
		lb2.AutoSize = lb1.AutoSize;
		lb2.Size = lb1.Size;

		lb3.Text = L"Hiển thị các từ trong danh sách nhắc nhở";
		lb3.Location.X = lb1.Location.X;
		lb3.Location.Y = lb2.Location.Y + 2;
		lb3.BackgroundFontColor = lb1.BackgroundFontColor;
		lb3.FontColor = lb1.FontColor;
		lb3.AutoSize = lb1.AutoSize;
		lb3.Size = lb1.Size;

		lb4.Text = L"Đặt lại dữ liệu gốc";
		lb4.Location.X = lb1.Location.X;
		lb4.Location.Y = lb3 .Location.Y + 2;
		lb4.BackgroundFontColor = lb1.BackgroundFontColor;
		lb4.FontColor = lb1.FontColor;
		lb4.AutoSize = lb1.AutoSize;
		lb4.Size = lb1.Size;

		system("cls");
		menu_caidat.Refresh();
		lb1.Refresh();
		lb2.Refresh();
		lb3.Refresh();
		lb4.Refresh();

		int KeyCode;

		while (true)
		{
			KeyCode = _getch();
			if (KeyCode == 13)
			{
				if (lb4.IsMe())
				{
					lb4.Hightlight();
					Sleep(100);
					lb4.Hightlight();
					ResetData();
					if (MessageBoxW(NULL,
						( LPCWSTR )L"Đặt lại dữ liệu thành công !\nThay đổi sẽ được cập nhật trong lần khởi động lại tiếp theo\nBạn muốn khởi động lại APP ?", ( LPCWSTR )L"Thông báo", MB_OKCANCEL | MB_ICONINFORMATION)
						== IDOK)
					{
						system("Dictionary.exe");
						Sleep(1000);
						exit(0);
					}
				}
			}
		}

		
	}

	void Show_KQ()
	{
		if (word_search.length() == 0)
		{
			BanDich.Text = L"Không có từ nào để dịch !";
			BanDich.Refresh();
			for (int i = 0; i < 4; i++)
			{
				DeXuat[i].Text = L"";
				DeXuat[i].FontColor = Color.Green + Light;
				DeXuat[i].BackgroundFontColor = Default_BackgroundFontColor;
				DeXuat[i].Refresh();
			}
			SearchBox << L"Nhập từ muốn dịch vào đây !";
		}
		else
		{
			if (Vitri_Muiten == 100)
			{
				//int Temp = 0;
				//if (word_search == Db->DeXuat[0]) Temp = 1;
				for (int i = 0; i < 4; i++)
				{
					if (i < Db->NumberOfDeXuat) //- Temp)
					{
						DeXuat[i].Text = Db->DeXuat[i]; //+ Temp];
					}
					else
					{
						DeXuat[i].Text = L"";
					}

					DeXuat[i].FontColor = Color.Green + Light;
					DeXuat[i].BackgroundFontColor = Default_BackgroundFontColor;
					DeXuat[i].Refresh();
				}
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					if (i < Db->NumberOfDeXuat)
					{
						if (i == Vitri_Muiten)
						{
							DeXuat[i].FontColor = Color.Yellow + Light;
							DeXuat[i].BackgroundFontColor = Color.Green;
						}
						else
						{
							DeXuat[i].FontColor = Color.Green + Light;
							DeXuat[i].BackgroundFontColor = Default_BackgroundFontColor;
						}
						DeXuat[i].Text = Db->DeXuat[i];
					}
					else
					{
						DeXuat[i].FontColor = Color.Green + Light;
						DeXuat[i].BackgroundFontColor = Default_BackgroundFontColor;
						DeXuat[i].Text = L"";
					}
					DeXuat[i].Refresh();
				}

				word_search = Db->DeXuat[Vitri_Muiten]; // +++++++++++++++++++++

			}

			if (Vitri_Muiten == 100)
			{
				if (Mean != NULL)
				{
					BanDich.Text = *Mean;
					if (BanDich.Text[0] == '@')
					{
						wstring Temp145 = BanDich.Text;
						Temp145.erase(0, 1);
						Mean = Db->Search(Temp145);
						if (Mean != NULL)
						{
							BanDich.Text = L"/ " + Temp145 + L" /: " + *Mean;
						}
					}
				}
				else BanDich.Text = word_search; // ++++++++++++++++++++++++++
			}
			else
			{
				BanDich.Text = L"< Nhấn phím ENTER để hiển thị kết quả của từ đang chọn >";
			}
			

			BanDich.Refresh();
			SearchBox << word_search + L"|";
		}
		
	}

	void EvenKeyDown()
	{
		word_search.clear();
		int KeyCode;
		while (true)
		{
			
			//--------------------------------------------------------------------------
			KeyCode = _getch();
			if ((KeyCode >= 97 && KeyCode <= 122) || // a -> z
				(KeyCode >= 65 && KeyCode <= 90)  || // A -> Z
				(KeyCode >= 48 && KeyCode <= 57)  || // 0 -> 9
				(KeyCode == 39)                   || // [ ' ]
				(KeyCode == 32)                   || // phím cách
				(KeyCode == 44)                   || // dấu phẩy
				(KeyCode == 40 || KeyCode == 41)  || // ( -> )
				(KeyCode == 46))                     // dấu chấm
			{
				word_search.push_back(KeyCode);
				Mean = Db->Search(word_search);

				Vitri_Muiten = 100;
				Show_KQ();
			}//--------------------------------------------------------------------------
			if (KeyCode == 8) // Phím xóa
			{
				if (word_search.length() > 0)
				{
					word_search.pop_back();
					if (word_search.length() > 0)
					{
						Mean = Db->Search(word_search);
					}
					Vitri_Muiten = 100;
					Show_KQ();
				}
			}//--------------------------------------------------------------------------
			if (KeyCode == 13) // Enter
			{
				if (Toa_Do_Select->X != 0 && Toa_Do_Select->Y != 0)
				{
					if (Lb_ClearSearchBox.IsMe() || Lb1_ClearSearchBox.IsMe())
					{
						Lb1_ClearSearchBox.Hightlight(); // Label Lam sach o tim kiem
						//---------------------------
						Toa_Do_Select->X = 0;
						Toa_Do_Select->Y = 0;
						word_search.clear();
						Mean = NULL;
						Show_KQ();
						//---------------------------
						Sleep(100);
						Lb1_ClearSearchBox.Hightlight();
					}
					if (Lb_Refresh.IsMe() || Lb1_Refresh.IsMe()) // Label Refresh
					{
						Lb1_Refresh.Hightlight();
						//---------------------------
						LamMoiManHinh();
						Show_KQ();		
						//---------------------------
						Sleep(100);
						Lb1_Refresh.Hightlight();
					}
					if (Lb_Options.IsMe() || Lb1_Options.IsMe()) // Label Options
					{
						Lb1_Options.Hightlight();
						Sleep(100);
						Lb1_Options.Hightlight();
						MenuCaiDat();
						LamMoiManHinh();
						Show_KQ();
					}
					if (Lb1_ADD.IsMe() || Lb_ADD.IsMe()) // Label Them tu moi
					{
						Lb1_ADD.Hightlight();
						Sleep(100);
						Lb1_ADD.Hightlight();
						ThemTuMoi();
						LamMoiManHinh();
						Show_KQ();
					}
					if (Lb_RemoveTudangtra.IsMe() || Lb1_RemoveTudangtra.IsMe()) // Label Xoa tu
					{
						Lb1_RemoveTudangtra.Hightlight();
						Sleep(100);
						Lb1_RemoveTudangtra.Hightlight();
						if (Db->RemoveItem(word_search))
							MessageBoxW(NULL, ( LPCWSTR )L"Đã xóa thành công !", (LPCWSTR )L"Thông báo", NULL);
						else MessageBoxW(NULL, ( LPCWSTR )L"Thất bại !", ( LPCWSTR )L"Thông báo", MB_ICONERROR);
						Mean = NULL;
						word_search.clear();
						LamMoiManHinh();
						Show_KQ();
					}
					if (Lb1_LuuThayDoi.IsMe() || Lb_LuuThayDoi.IsMe()) // Label Them tu moi
					{
						Lb1_LuuThayDoi.Hightlight();
						Sleep(100);
						Lb1_LuuThayDoi.Hightlight();

						Db->SaveDatabase();


						LamMoiManHinh();
						Show_KQ();
					}


					Toa_Do_Select->X = 0;
					Toa_Do_Select->Y = 0;
				}
				else
				{
					if (word_search.length() > 0)
					{
						Mean = Db->Search(word_search);
					}
					Vitri_Muiten = 100;
					Show_KQ();
				}
				


				
			}//--------------------------------------------------------------------------
			if (KeyCode == 224) //  Phim mui ten
			{
				KeyCode = _getch();
				if (KeyCode == 72)
				{
					if (Vitri_Muiten == 100 || Vitri_Muiten < 0) Vitri_Muiten = Db->NumberOfDeXuat - 1;
					else
					{
						Vitri_Muiten--;
						if (Vitri_Muiten < 0) Vitri_Muiten = Db->NumberOfDeXuat - 1;
					}
					Show_KQ();
				}
				if (KeyCode == 80)
				{

					if (Vitri_Muiten == 100 || Vitri_Muiten >= Db->NumberOfDeXuat) Vitri_Muiten = 0;
					else
					{
						Vitri_Muiten++;
						if (Vitri_Muiten >= Db->NumberOfDeXuat) Vitri_Muiten = 0;
					}
					Show_KQ();
				}
				if (KeyCode == 83) // delete
				{
					word_search.clear();
					Mean = NULL;
					Show_KQ();
				}
			}
			if (KeyCode == 0) // Sự kiện cho các phím F
			{

				if (Lb_ClearSearchBox.IsMe() || Lb1_ClearSearchBox.IsMe())
				{
					word_search.clear();
					Mean = NULL;
					Show_KQ();
				}
				KeyCode = _getch();
				if (KeyCode == 59) // F1
				{
					LamMoiManHinh();
					Show_KQ();
				}
				if (KeyCode == 60) // F2
				{
					MenuCaiDat();
					LamMoiManHinh();
					Show_KQ();
				}
				if (KeyCode == 61)// F3
				{
					ThemTuMoi();
					LamMoiManHinh();
					Show_KQ();
				}
			}
			//--------------------------------------------------------------------------
		}
	}

	void Run_Mainform()
	{
		Load_Mainform();
		Show_KQ();
		EvenKeyDown();
	}
};

Main_From::Main_From()
{
	Load();
}
Main_From::~Main_From()
{

}

