#include<AppManager.h>

int main() {
	AppManager appManager{1080, 720, "Raylib Game", 144};
	appManager.Run();

	return 0;
}