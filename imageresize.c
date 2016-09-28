#include <stdlib.h>
#include <stdio.h>
//#include <wlc/wlc.h>
//#include <wlc/wlc-wayland.h>
//#include <wlc/wlc-render.h>
#include <linux/input.h>
//#include <cairo/cairo.h>
#include <memory.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk/gdk.h>

void
main(int argc, char **argv)
{

        GdkPixbuf *image;
        //cairo_t *cr;
        //cairo_surface_t *cairo_surface;


        char *outname=NULL;
        char *inname=NULL;
        char *format=NULL;
        int  screen_w;
        int  screen_h;
        char *qual=NULL;
        const GOptionEntry options[]={
                {
                        "input", 'i', 0,
                        G_OPTION_ARG_FILENAME, &inname,    // G_OPTION_ARG_INT,G_OPTION_ARG_STRING,G_OPTION_ARG_NONE,G_OPTION_ARG_FILENAME
                        "Input Filename", NULL
                },
                              {
                        "output", 'o', 0,
                        G_OPTION_ARG_FILENAME, &outname,    // G_OPTION_ARG_INT,G_OPTION_ARG_STRING,G_OPTION_ARG_NONE,G_OPTION_ARG_FILENAME
                        "Output Filename", NULL
                },
                {
                        "format", 'f', 0,
                        G_OPTION_ARG_STRING, &format,    // G_OPTION_ARG_INT,G_OPTION_ARG_STRING,G_OPTION_ARG_NONE,G_OPTION_ARG_FILENAME
                        "Output Format: png,jpeg,bmp,ico,...", NULL
                },
                {
                        "sizex", 'x', 0,
                        G_OPTION_ARG_INT, &screen_w,    // G_OPTION_ARG_INT,G_OPTION_ARG_STRING,G_OPTION_ARG_NONE,G_OPTION_ARG_FILENAME
                        "Resize to X Pixels", NULL
                },
                {
                        "sizey", 'y', 0,
                        G_OPTION_ARG_INT, &screen_h,    // G_OPTION_ARG_INT,G_OPTION_ARG_STRING,G_OPTION_ARG_NONE,G_OPTION_ARG_FILENAME
                        "Resize to Y Pixels", NULL
                },
                {
                        "qual", 'q', 0,
                        G_OPTION_ARG_STRING, &qual,    // G_OPTION_ARG_INT,G_OPTION_ARG_STRING,G_OPTION_ARG_NONE,G_OPTION_ARG_FILENAME
                        "Output Quality 1-100", NULL
                },                
        { NULL }
        };
        GOptionContext *context;
        GError *error = NULL;       
        context = g_option_context_new (" - Imageresizer");
        g_option_context_add_main_entries (context, options, NULL);
        //g_option_context_add_group (context, gtk_get_option_group (TRUE));
        g_option_context_parse (context, &argc, &argv, &error);
        g_option_context_free (context);
        if (error != NULL) {
            g_printerr ("Failed to parse command line arguments: %s\n",error->message);
            g_error_free (error);
            return ;
        }

        if (inname==NULL) return;
        image = gdk_pixbuf_new_from_file_at_size (inname, screen_w, screen_h, 0);
        if (image == NULL) return;
        
        //cairo_surface = cairo_image_surface_create (CAIRO_FORMAT_RGB24, screen_w, screen_h);
        //cr = cairo_create (cairo_surface);
        //gdk_cairo_set_source_pixbuf(cr, image, 0, 0);
        //cairo_paint(cr);
        //cairo_status_t cstatus = cairo_surface_write_to_png (cairo_surface,"output.png");
        
        //printf ("outname %s format %s  qual %d  \n",outname,format,qual);
        gdk_pixbuf_save(image,outname,format,0,"quality",qual,NULL);
        
        //gdk_pixbuf_save(image,"out","jpeg",0,"quality","100",NULL);
        
        //cairo_destroy(cr);
        //cairo_surface_destroy(cairo_surface);
}
