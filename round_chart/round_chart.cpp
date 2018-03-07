#include "CImg.h"
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	/*
	Выбрал 3 компоненты на пиксель, так как такая программа:
	```
	cimg_library::CImg<unsigned char> img(1024, 1024); // A img = image:(1024, 1024) // А рис = изобр:(1024, 1024)
	img.save("round_chart.png");
	```
	вылетает с ошибкой [CImg] *** CImgIOException *** [instance(1024,1024,1,1,0274E040,non-shared)] CImg<unsigned char>::save_other(): Failed to save file 'round_chart.png'. Format is not natively supported, and no external commands succeeded.
	*/
	cimg_library::CImg<unsigned char> img(1024, 1024, 1, 3); // A img = image:(1024, 1024, 3)                        // А рис = изобр:(1024, 1024, 3)
	img.fill(255, 255, 255);                                 // img.fill((255, 255, 255))                            // рис.заполнить((255, 255, 255))
	unsigned char black_color[3] = {0, 0, 0};
	img.draw_circle(512, 512, 256, black_color, 1, 0);       // img.draw_circle((512, 512), 256, (0, 0, 0))          // рис.нарисовать_круг((512, 512), 256, (0, 0, 0))
	for (int i=0; i<24; i++) {
		char t[3];
		float angle = float((i+0.5)*2*M_PI/24.0);            // A angle = (i+0.5)*2*PI/24                            // А угол = (i+0.5)*2*PI/24
		img.draw_text(512 + int(sin(angle)*200),             // img.draw_text(512 + (sin(angle),-cos(angle))*200, i) // риc.отобразить_текст(512 + (sin(angle),-cos(angle))*200, i)
			          512 + int(-cos(angle)*200),
					  (_itoa_s(i, t, 10), t), black_color);
	}
	img.save("round_chart.bmp");                             // img.save(‘round_chart.bmp’)                          // рис.сохрани(‘round_chart.bmp’)
}
