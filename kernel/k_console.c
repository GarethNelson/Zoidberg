#include "k_console.h"
#include "kmsg.h"

int term_damage(VTermRect rect, __unused void* user)
{
    /* TODO: Reimplement in a less slow-ass way */
    VTermScreenCell cell;
    VTermPos pos;
    uint8_t fg, bg, color;
    int row, col;
    for (row = rect.start_row; row < rect.end_row; row++)
    for (col = rect.start_col; col < rect.end_col; col++)
    {
        pos.col = col;
        pos.row = row;
        vterm_screen_get_cell(vscreen, pos, &cell);
//        fg = rgb2vga(cell.fg.red, cell.fg.green, cell.fg.blue);
//        bg = rgb2vga(cell.bg.red, cell.bg.green, cell.bg.blue);

        if (cell.attrs.reverse)
            color = bg | (fg << 4);
        else
            color = fg | (bg << 4);
//        display_put(col, row, cell.chars[0], color);
    }
    return 1;
}

static VTerm *console_term=NULL; 
static VTermScreen* vscreen=NULL;

static VTermScreenCallbacks vtsc =
{
    .damage = &term_damage,
    .moverect = NULL,
    .movecursor = NULL,
    .settermprop = NULL,
    .bell = NULL,
    .resize = NULL,
};

void init_console() {
     klog("CONSOLE",1,"Configuring vterm for system console");
     console_term = vterm_new(80,25);    

     if(console_term==NULL) {
        klog("TERM",0,"Failed to create libvterm terminal");
     } else {
        klog("TERM",1,"Created libvterm terminal");
        vscreen = vterm_obtain_screen(console_term);
        vterm_screen_set_callbacks(vscreen, &vtsc, NULL);
        vterm_screen_enable_altscreen(vscreen, 1);
        vterm_screen_reset(vscreen, 1);
     }

}
