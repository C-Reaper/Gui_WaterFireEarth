#if defined __linux__
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#elif defined _WINE
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#elif defined _WIN32
#include "F:/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "F:/home/codeleaded/System/Static/Library/TransformedView.h"
#include "F:/home/codeleaded/System/Static/Library/Random.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif


void Setup(AlxWindow* w){
	
}
void Update(AlxWindow* w){
	if(Stroke(ALX_MOUSE_L).PRESSED){
		
	}

	Clear(BLACK);

	// for (int i = (int)wtl.y;i<(int)wbr.y + 1;i++){
	// 	for (int j = (int)wtl.x;j<(int)wbr.x + 1;j++){
	// 	}
	// }
}
void Delete(AlxWindow* w){
	
}

int main(){
    if(Create("Water Fire Earth",1600,1000,1,1,Setup,Update,Delete))
        Start();
    return 0;
}