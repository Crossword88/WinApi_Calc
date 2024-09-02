#include <Windows.h>
#include <string>
#include <iostream>
#include <vector>

HWND hEdit;
std::string text = "";
std::string sum = "";
std::vector<char> action;

HWND hButtonPlus;
HWND hButtonMinus;
HWND hButtonMultiplic;
HWND hButtonDivision;
HWND hButtonEquals;

std::vector<int> numbers(int sz, LPSTR text, std::vector<int> numbers)
{
	std::string num = "";
	for (int i = 0; i < sz; i++)
	{
		if (text[i] != '+' && text[i] != '-' && text[i] != 'x' && text[i] != '/')
		{
			num += text[i];
		}
		else
		{
			numbers.push_back(std::stoi(num));
			action.push_back(text[i]);
			num = "";
		}
	}
	numbers.push_back(std::stoi(num));

	return numbers;
}

float res(const std::vector<int> nums)
{
	float sum = nums[0];
	for (int i = 0; i < action.size(); i++)
	{
		if (action[i] == '+')
			sum += nums[i+1];
		else if (action[i] == '-')
			sum -= nums[i+1];
		else if (action[i] == 'x')
			sum *= nums[i+1];
		else if (action[i] == '/')
			sum /= nums[i+1];
	}
	return sum;
}

float count()
{
	int cTxtLen = GetWindowTextLength(hEdit)+1;
	LPSTR pszMem = (PSTR)VirtualAlloc((LPVOID)NULL, (DWORD)(cTxtLen + 1), MEM_COMMIT, PAGE_READWRITE);
	GetWindowText(hEdit, pszMem, cTxtLen);

	std::vector<int> numerics = numbers(cTxtLen, pszMem, numerics);

	float result = res(numerics);

	action.clear();

	VirtualFree(pszMem, 0, MEM_RELEASE);
	
	return result;
}

int	CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCmdLine, int nCmdShow)
{
	MSG msg{};
	HWND hwnd{};
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadCursor(nullptr, IDI_APPLICATION);
	wc.hInstance = hInstance;

	wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT
	{
		switch (uMsg)
		{
		case WM_CREATE:
		{
			hEdit = CreateWindow(
				"EDIT",
				NULL,
				WS_CHILD | WS_VISIBLE,
				100, 50, 300, 30, hWnd, reinterpret_cast<HMENU>(0), nullptr, nullptr
			);

			HWND hButton1 = CreateWindow(
				"BUTTON",
				"1",
				WS_CHILD | WS_VISIBLE,
				100, 100, 50, 30, hWnd, reinterpret_cast<HMENU>(1), nullptr, nullptr
			);

			HWND hButton2 = CreateWindow(
				"BUTTON",
				"2",
				WS_CHILD | WS_VISIBLE,
				150, 100, 50, 30, hWnd, reinterpret_cast<HMENU>(2), nullptr, nullptr
			);

			HWND hButton3 = CreateWindow(
				"BUTTON",
				"3",
				WS_CHILD | WS_VISIBLE,
				200, 100, 50, 30, hWnd, reinterpret_cast<HMENU>(3), nullptr, nullptr
			);

			HWND hButton4 = CreateWindow(
				"BUTTON",
				"4",
				WS_CHILD | WS_VISIBLE,
				100, 150, 50, 30, hWnd, reinterpret_cast<HMENU>(4), nullptr, nullptr
			);

			HWND hButton5 = CreateWindow(
				"BUTTON",
				"5",
				WS_CHILD | WS_VISIBLE,
				150, 150, 50, 30, hWnd, reinterpret_cast<HMENU>(5), nullptr, nullptr
			);

			HWND hButton6 = CreateWindow(
				"BUTTON",
				"6",
				WS_CHILD | WS_VISIBLE,
				200, 150, 50, 30, hWnd, reinterpret_cast<HMENU>(6), nullptr, nullptr
			);

			HWND hButton7 = CreateWindow(
				"BUTTON",
				"7",
				WS_CHILD | WS_VISIBLE,
				100, 200, 50, 30, hWnd, reinterpret_cast<HMENU>(7), nullptr, nullptr
			);

			HWND hButton8 = CreateWindow(
				"BUTTON",
				"8",
				WS_CHILD | WS_VISIBLE,
				150, 200, 50, 30, hWnd, reinterpret_cast<HMENU>(8), nullptr, nullptr
			);

			HWND hButton9 = CreateWindow(
				"BUTTON",
				"9",
				WS_CHILD | WS_VISIBLE,
				200, 200, 50, 30, hWnd, reinterpret_cast<HMENU>(9), nullptr, nullptr
			);

			HWND hButton0 = CreateWindow(
				"BUTTON",
				"0",
				WS_CHILD | WS_VISIBLE,
				150, 250, 50, 30, hWnd, reinterpret_cast<HMENU>(10), nullptr, nullptr
			);

			hButtonPlus = CreateWindow(
				"BUTTON",
				"+",
				WS_CHILD | WS_VISIBLE,
				300, 100, 50, 30, hWnd, reinterpret_cast<HMENU>(20), nullptr, nullptr
			);

			hButtonMinus = CreateWindow(
				"BUTTON",
				"-",
				WS_CHILD | WS_VISIBLE,
				300, 150, 50, 30, hWnd, reinterpret_cast<HMENU>(30), nullptr, nullptr
			);

			hButtonMultiplic = CreateWindow(
				"BUTTON",
				"x",
				WS_CHILD | WS_VISIBLE,
				350, 100, 50, 30, hWnd, reinterpret_cast<HMENU>(40), nullptr, nullptr
			);

			hButtonDivision = CreateWindow(
				"BUTTON",
				"/",
				WS_CHILD | WS_VISIBLE,
				350, 150, 50, 30, hWnd, reinterpret_cast<HMENU>(50), nullptr, nullptr
			);

			hButtonEquals = CreateWindow(
				"BUTTON",
				"=",
				WS_CHILD | WS_VISIBLE,
				325, 200, 50, 30, hWnd, reinterpret_cast<HMENU>(100), nullptr, nullptr
			);

			HWND hButtonClear = CreateWindow(
				"BUTTON",
				"CA",
				WS_CHILD | WS_VISIBLE,
				325, 300, 50, 30, hWnd, reinterpret_cast<HMENU>(101), nullptr, nullptr
			);


		}
		return 0;

		
		case WM_COMMAND:
		{
			EnableWindow(hButtonPlus, 1);
			EnableWindow(hButtonMinus, 1);
			EnableWindow(hButtonMultiplic, 1);
			EnableWindow(hButtonDivision, 1);
			EnableWindow(hButtonEquals, 1);
			switch (LOWORD(wParam))
			{
			case 1:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;

			case 2:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;


			case 3:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;

			case 4:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;

			case 5:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;

			case 6:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;

			case 7:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;

			case 8:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;

			case 9:
				text += std::to_string(LOWORD(wParam));
				SetWindowText(hEdit, text.c_str());
				break;

			case 10:
				text += std::to_string(0);
				SetWindowText(hEdit, text.c_str());
				break;

			case 20:
				text += '+';
				SetWindowText(hEdit, text.c_str());
				EnableWindow(hButtonPlus, 0);
				EnableWindow(hButtonMinus, 0);
				EnableWindow(hButtonMultiplic, 0);
				EnableWindow(hButtonDivision, 0);
				EnableWindow(hButtonEquals, 0);
				break;

			case 30:
				text += '-';
				SetWindowText(hEdit, text.c_str());
				EnableWindow(hButtonPlus, 0);
				EnableWindow(hButtonMinus, 0);
				EnableWindow(hButtonMultiplic, 0);
				EnableWindow(hButtonDivision, 0);
				EnableWindow(hButtonEquals, 0);
				break;

			case 40:
				text += 'x';
				SetWindowText(hEdit, text.c_str());
				EnableWindow(hButtonPlus, 0);
				EnableWindow(hButtonMinus, 0);
				EnableWindow(hButtonMultiplic, 0);
				EnableWindow(hButtonDivision, 0);
				EnableWindow(hButtonEquals, 0);
				break;

			case 50:
				text += '/';
				SetWindowText(hEdit, text.c_str());
				EnableWindow(hButtonPlus, 0);
				EnableWindow(hButtonMinus, 0);
				EnableWindow(hButtonMultiplic, 0);
				EnableWindow(hButtonDivision, 0);
				EnableWindow(hButtonEquals, 0);
				break;


			case 100:
				sum = std::to_string(count());
				SetWindowText(hEdit, sum.c_str());
				text = sum;
				sum = "";
				break;

			case 101:
				SetWindowText(hEdit, "");
				text = "";
				break;

			default:
				break;
			}
		}
		return 0;

		case WM_DESTROY:
		{
			PostQuitMessage(EXIT_SUCCESS);
		}
		break;
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	};
	wc.lpszClassName = "MyAppClass";
	wc.lpszMenuName = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&wc))
		return EXIT_FAILURE;

	hwnd = CreateWindow(wc.lpszClassName, "Calc!", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600, nullptr, nullptr, wc.hInstance, nullptr);
	if (hwnd == INVALID_HANDLE_VALUE)
		return EXIT_FAILURE;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.wParam);
}
