#include "Spegetti API.h"

#pragma

using namespace Spegetti_API;

namespace Spegetti_Demo {

	bool Running = true;

	//OS::Window win;

	class Player {

	public:
		
		Math::Transform3D transform;
		PhysicsWorld3D::RigidBody3D rigid;

		World3D::Camera Camera;

		float sensitivity = 0.05f;

		void Start() {

			//Lock mouse

			rigid.LockAxis(true, false, true);

		}

		void Update() {

			//Camera.transform.rotation.x += Input::Mouse::mousePosition.y * sensitivity;
			//transform.rotation.y += Input::Mouse::mousePosition.x * sensitivity;

			Camera.transform.rotation.x = Math::clamp(Camera.transform.rotation.x, -90, 90);

			//vec2 input_direction = vec2(Input::Key_Is(KEY_W) - Input::Key_Is(KEY_S), Input::Key_Is(KEY_A) - Input::Key_Is(KEY_D));

			//rigid.apply(vec3(input_direction.x * vec3.forward, 0, input_direction.y * vec3.right) * 10);

		}

		void Destroy() {

		

		}

	};

	//Player player;

	void Start() {

		Console::print("Hello, World!");
		Console::print(OS::Get_Spegetti_Version());

		//win.Create();

	}

	void Loop() {

		//win.Update();

	}

	void End() {

		//win.Destroy();

	}

}