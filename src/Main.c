#if defined __linux__
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#elif defined _WINE
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#elif defined _WIN32
#include "F:/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "F:/home/codeleaded/System/Static/Library/Random.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif


float* buffer1 = NULL;
float* buffer2 = NULL;
const float dampening = 0.99f;

void Resize(AlxWindow* w){
	if(buffer1) free(buffer1);
	buffer1 = (float*)malloc(sizeof(float) * w->Width * w->Height);
	memset(buffer1,0,sizeof(float) * w->Width * w->Height);
	
	if(buffer2) free(buffer2);
	buffer2 = (float*)malloc(sizeof(float) * w->Width * w->Height);
	memset(buffer2,0,sizeof(float) * w->Width * w->Height);
}
void Setup(AlxWindow* w){
	buffer1 = (float*)malloc(sizeof(float) * w->Width * w->Height);
	memset(buffer1,0,sizeof(float) * w->Width * w->Height);
	
	buffer2 = (float*)malloc(sizeof(float) * w->Width * w->Height);
	memset(buffer2,0,sizeof(float) * w->Width * w->Height);
    
	Resize(w);
}
void Update(AlxWindow* w){
	if(Stroke(ALX_MOUSE_L).PRESSED){
		buffer1[w->MouseY * w->Width + w->MouseX] = 100.0f;
	}

	Clear(BLACK);

	for (int i = 1;i<w->Height - 1;i++){
		for (int j = 1;j<w->Width - 1;j++){
			buffer1[i * w->Width + j] = (
				buffer2[(i - 1) * w->Width + j] + 
				buffer2[(i + 1) * w->Width + j] + 
				buffer2[i * w->Width + (j - 1)] + 
				buffer2[i * w->Width + (j + 1)]
			) * 0.5f - buffer1[i * w->Width + j];

			buffer1[i * w->Width + j] *= dampening;

			const float l = F32_Clamp(buffer1[i * w->Width + j],0.0f,1.0f);
			w->Buffer[i * w->Width + j] = Pixel_toRGBA(l,l,l,1.0f);
		}
	}

	float* const temp = buffer1;
	buffer1 = buffer2;
	buffer2 = temp;
}
void Delete(AlxWindow* w){
	if(buffer1) free(buffer1);
	buffer1 = NULL;

	if(buffer2) free(buffer2);
	buffer2 = NULL;
}

int main(){
    if(CreateX("Water Fire Earth",800,600,2,2,Setup,Update,Delete,Resize))
        Start();
    return 0;
}