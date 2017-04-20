package org.thingml.generated.api;

import org.thingml.generated.api.*;

public interface IBouncingBall_displayClient{
void create_from_display(int DisplayMsgs_create_xsize_var, int DisplayMsgs_create_ysize_var);
void fillRect_from_display(int DisplayMsgs_fillRect_x_var, int DisplayMsgs_fillRect_y_var, int DisplayMsgs_fillRect_width_var, int DisplayMsgs_fillRect_height_var);
void drawRect_from_display(int DisplayMsgs_drawRect_x_var, int DisplayMsgs_drawRect_y_var, int DisplayMsgs_drawRect_width_var, int DisplayMsgs_drawRect_height_var);
void clear_from_display();
void setColor_from_display(int DisplayMsgs_setColor_r_var, int DisplayMsgs_setColor_g_var, int DisplayMsgs_setColor_b_var);
void update_from_display();
}