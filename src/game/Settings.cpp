#include"Settings.h"

void Settings::DrawFPSText() {
	if(showFPS) {
		::DrawFPS(20, 20);
	}
}