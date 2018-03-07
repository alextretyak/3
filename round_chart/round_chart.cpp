#include "CImg.h"
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	float data[24] = {10000};                                 // Float[24] data = [10'000] [+] Float[23](0)              // Дробн[24] данные = [10'000] [+] Дробн[23](0)
	float max = *std::max_element(data, data+_countof(data)); // A max = a:max(data)                                     // А макс = а:макс(данные)

	/*
	Выбрал 3 компоненты на пиксель, так как такая программа:
	```
	cimg_library::CImg<unsigned char> img(1024, 1024);        // A img = image:(1024, 1024)                              // А рис = изобр:(1024, 1024)
	img.save("round_chart.png");
	```
	вылетает с ошибкой [CImg] *** CImgIOException *** [instance(1024,1024,1,1,0274E040,non-shared)] CImg<unsigned char>::save_other(): Failed to save file 'round_chart.png'. Format is not natively supported, and no external commands succeeded.
	*/
	cimg_library::CImg<unsigned char> img(1024, 1024, 1, 3);  // A img = image:[3](1024, 1024)                           // А рис = изобр:[3](1024, 1024)
	img.fill(255, 255, 255);                                  // img.fill((255, 255, 255))                               // рис.заполнить((255, 255, 255))
	unsigned char black_color[3] = {0, 0, 0};
	img.draw_circle(512, 512, 256, black_color, 1, 0);        // img.draw_circle((512, 512), 256, (0, 0, 0))             // рис.круг((512, 512), 256, (0, 0, 0))
	for (int i=0; i<24; i++) {                                // L(i) 24                                                 // Ц(и) 24
		struct float2 {float x, y;};
		auto f = [](float i) {                                //    F f(i)
			float angle = float(i*2*M_PI/24.0);               //       A angle = i*2*PI/24                               //    А угол = (и+0.5)*2*ПИ/24
			float2 r;                                         //       R (sin(angle), -cos(angle))
			r.x = sin(angle);
			r.y =-cos(angle);
			return r;
		};
		float2 d = f(i+0.5f);                                 
		char t[3];
		img.draw_text(512 + int(d.x*200),                     //    img.draw_text(512 + f(i+0.5)*200, i)                 //    риc.текст(512 + напр*200, и)
		              512 + int(d.y*200),
		              (_itoa_s(i, t, 10), t), black_color);
		float2 d1 = f((float)i),
		       d2 = f((float)i+1);
		float k = 1 + data[i]/max;                            //    A k = 1 + data[i]/max
		img.draw_line(512 + int(d1.x*256),                    //    img.draw_line(512 + d1*256  , 512 + d1*256*k)          //    риc.линия(512 + напр*256, 512 + напр*256*данные[i]/макс)
		              512 + int(d1.y*256),
		   	          512 + int(d1.x*256*k),
		              512 + int(d1.y*256*k), black_color);
		img.draw_line(512 + int(d1.x*256*k),                  //    img.draw_line(512 + d1*256*k, 512 + d2*256*k)
		              512 + int(d1.y*256*k),
		   	          512 + int(d2.x*256*k),
		              512 + int(d2.y*256*k), black_color);
		img.draw_line(512 + int(d2.x*256*k),                  //    img.draw_line(512 + d2*256*k, 512 + d2*256)
		              512 + int(d2.y*256*k),
		   	          512 + int(d2.x*256),
		              512 + int(d2.y*256), black_color);
	}

	img.save("round_chart.bmp");                              // img.save(‘round_chart.bmp’)                             // рис.сохрани(‘round_chart.bmp’)
}
