#include<AppManager.h>

int main() {
	AppManager appManager{1920, 1080, "Raylib Game", 144};
	appManager.Run();

	return 0;
}