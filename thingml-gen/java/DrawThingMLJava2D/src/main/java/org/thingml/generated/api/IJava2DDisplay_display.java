package org.thingml.generated.api;

import org.thingml.generated.api.*;

public interface IJava2DDisplay_display{
void create_via_display(int DisplayMsgs_create_xsize_var, int DisplayMsgs_create_ysize_var);
void destroy_via_display();
void update_via_display();
void clear_via_display();
void setColor_via_display(int DisplayMsgs_setColor_r_var, int DisplayMsgs_setColor_g_var, int DisplayMsgs_setColor_b_var);
void setBGColor_via_display(int DisplayMsgs_setBGColor_r_var, int DisplayMsgs_setBGColor_g_var, int DisplayMsgs_setBGColor_b_var);
void drawRect_via_display(int DisplayMsgs_drawRect_x_var, int DisplayMsgs_drawRect_y_var, int DisplayMsgs_drawRect_width_var, int DisplayMsgs_drawRect_height_var);
void fillRect_via_display(int DisplayMsgs_fillRect_x_var, int DisplayMsgs_fillRect_y_var, int DisplayMsgs_fillRect_width_var, int DisplayMsgs_fillRect_height_var);
void drawInteger_via_display(int DisplayMsgs_drawInteger_x_var, int DisplayMsgs_drawInteger_y_var, int DisplayMsgs_drawInteger_v_var, int DisplayMsgs_drawInteger_digits_var, int DisplayMsgs_drawInteger_scale_var);
}