#include <iostream>
#include <ctime>

#pragma once

#ifdef __linux__ //NEED TO CHECK

#include <X11/Xlib.h>

#endif

#ifdef _WIN32

#include <Windows.h>

#endif

#ifdef __APPLE__ //NEED TO CHECK (I cant check btw D: )

//Mac Dependences

#endif

#ifndef Spegetti_Version

#define Spegetti_Version "engine build : 6-16-2024";

#endif

namespace Spegetti_API {

	namespace OS {

		std::string Get_Spegetti_Version() {

			return Spegetti_Version;

		}

		/*class Window {

		public:

			bool running = true;

			void Create() {

				const wchar_t* CLASS_NAME = L"HELLO WINDOW!"; //CLASS NAME

				WNDCLASS wndClass = {};
				wndClass.lpszClassName = CLASS_NAME;
				wndClass.hInstance = m_hInstance;
				wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
				wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
				wndClass.lpfnWndProc = WindowProc;

				RegisterClass(&wndClass);

				DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

				int width = 640;
				int height = 480;

				RECT rect;
				rect.left = 250; //position X
				rect.top = 250; //position Y
				rect.right = rect.left + width; //size X
				rect.bottom = rect.top + height; //size Y

				AdjustWindowRect(&rect, style, false);

				m_hWnd = CreateWindowEx(0, CLASS_NAME, L"HELLO WINDOW", style, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, m_hInstance, NULL);

				ShowWindow(m_hWnd, SW_SHOW);

			}

			void Destroy() {

				const wchar_t* CLASS_NAME = L"HELLO WINDOW!"; //CLASS NAME

				UnregisterClass(CLASS_NAME, m_hInstance);

			}

			~Window() {

				const wchar_t* CLASS_NAME = L"HELLO WINDOW!"; //CLASS NAME

				UnregisterClass(CLASS_NAME, m_hInstance);

			}

			void Update() {

				MSG msg = {};

				while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {

					if (msg.message == WM_QUIT) {

						Destroy();

					}

					TranslateMessage(&msg);
					DispatchMessage(&msg);

				}

			}

		private:

			HINSTANCE m_hInstance;
			HWND m_hWnd;

		}; */

	}

	namespace Input {

		namespace Mouse {

			//Math::vec2 mousePosition;

		}

	}

	namespace Math {

		float clamp(float value, float max, float min) {

			if (value > max) {

				return max;

			} else {

				if (value < min) {

					return min;

				} else {

					return value;

				}

			}

		}

		struct vec2 {

			float x, y;

			vec2();
			vec2(float x, float y) : x(0.0), y(0.0) {}

			vec2 operator+(vec2 other) {

				return vec2(x + other.x, y + other.y);

			}

			vec2 operator-(vec2 other) {

				return vec2(x - other.x, y - other.y);

			}

			vec2 operator*(vec2 other) {

				return vec2(x * other.x, y * other.y);

			}

			vec2 operator/(vec2 other) {

				return vec2(x / other.x, y / other.y);

			}

			vec2 ZERO() {

				return vec2(0, 0);

			}

			float dot(vec2 other) {

				return (x + other.x) * (y + other.y);

			}

			vec2 cross(vec2 other) {

				return vec2(x + other.y, y + other.x);

			}

		};

		struct vec3 {

			float x, y, z;

			vec3(float x, float y, float z) : x(0.0), y(0.0), z(0.0) {}

			vec3 operator+(vec3 other) {

				return vec3(x + other.x, y + other.y, z + other.z);

			}

			vec3 operator-(vec3 other) {

				return vec3(x - other.x, y - other.y, z - other.z);

			}

			vec3 operator*(vec3 other) {

				return vec3(x * other.x, y * other.y, z * other.z);

			}

			vec3 operator/(vec3 other) {

				return vec3(x / other.x, y / other.y, z / other.z);

			}

			vec3 ZERO() {

				return vec3(0, 0, 0);

			}

			float dot(vec3 other) {

				return (x + other.x) * (y + other.y) * (z + other.z);

			}

			vec3 cross(vec3 other) {

				return vec3(x + other.z, y + other.x, z + other.y);

			}

		};


		struct Transform2D {

			vec2 position;
			vec2 rotation;
			vec2 scale;
			
			Transform2D(vec2 position, vec2 rotation, vec2 scale) : position(Math::vec2(0, 0)), rotation(Math::vec2(0, 0)), scale(Math::vec2(1, 1)) {}

		};

		struct Transform3D {

			vec3 position;
			vec3 rotation;
			vec3 scale;

			Transform3D(vec3 position, vec3 rotation, vec3 scale) : position(Math::vec3(0, 0, 0)), rotation(Math::vec3(0, 0, 0)), scale(Math::vec3(1, 1, 1)) {}

		};

	}

	namespace Console {

		void print(std::string text) {

			std::cout << text << std::endl;

		}

		void log(std::string text) {

			std::cout << text << std::endl;

		}

		void warn(std::string text) {

			std::cout << "WARN : " << text << std::endl;

		}

		void error(std::string text) {

			std::cout << "ERROR : " << text << std::endl;

		}

	};

	namespace PhysicsWorld3D {

		class RigidBody3D {
		
		public:

			void LockAxis(bool x, bool y, bool z) {

				//LOCK AXIS

			}

		};
	}

	namespace World3D {

		class Camera {
		
		public:
			
			Math::Transform3D transform;

		};

	}

}