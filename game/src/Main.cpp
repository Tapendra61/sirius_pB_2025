#include<game/WindowManager.h>

// Reminder:
// Working On Camera System
// TODO: Transforms

int main() {
	WindowManager winManager{1920, 1080, "Raylib Game", 144};
	winManager.Run();

	return 0;
}