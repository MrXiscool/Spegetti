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

#define Spegetti_Version "engine build : 6-3-2024";

#endif

namespace Spegetti {

	namespace OS {

		std::string Get_Spegetti_Version() {

			return Spegetti_Version;

		}

		class Window {
		public:

			HINSTANCE hInstance = GetModuleHandle(NULL);

			HWND hwnd;
			const char* CLASS_NAME = "Sample Window Class";
			const char* Title = "Sample Window";

			static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
				Window* windowPtr;
				if (uMsg == WM_NCCREATE) {
					windowPtr = static_cast<Window*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
					SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(windowPtr));
				}
				else {
					windowPtr = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
				}

				if (windowPtr) {
					return windowPtr->HandleMessage(uMsg, wParam, lParam);
				}
				else {
					return DefWindowProc(hwnd, uMsg, wParam, lParam);
				}
			}


			Window(HINSTANCE hInstance) : hwnd(nullptr) {

				WNDCLASS wc = {};
				wc.lpfnWndProc = WindowProc;
				wc.hInstance = hInstance;
				wc.lpszClassName = CLASS_NAME;
				RegisterClass(&wc);
			
			}

			void Create() {
				
				hwnd = CreateWindowEx(0, CLASS_NAME, Title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL, this);

				ShowWindow(hwnd, SW_SHOW);

			}

			void Update() {
				MSG msg = {};
				while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

					TranslateMessage(&msg);
					DispatchMessage(&msg);

				}
			}

			void Destroy() {

				if (hwnd) {
					DestroyWindow(hwnd);
					hwnd = nullptr;
				}

			}

		private:
			LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
				switch (uMsg) {
				case WM_CLOSE:
					PostQuitMessage(0);
					break;
				default:
					return DefWindowProc(hwnd, uMsg, wParam, lParam);
				}
				return 0;
			}
		};

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

			vec3();
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

		};

		struct Transform3D {

			vec3 position;
			vec3 rotation;
			vec3 scale;

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