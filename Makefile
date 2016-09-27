all:
	gcc imageresize.c -O2 -g -o imageresize `pkg-config gdk-pixbuf-2.0 gdk-3.0 --libs --cflags` 

clean:
	rm *~ 
	
