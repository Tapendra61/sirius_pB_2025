#include<WindowManager.h>

int main() {
	WindowManager winManager{1920, 1080, "Raylib Game", 144};
	winManager.Run();

	return 0;
}