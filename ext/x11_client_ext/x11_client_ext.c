#include "x11_client.h"

#include "x11_client_core.h"
#include "x11_client_display.h"
#include "x11_client_event.h"
#include "x11_client_mouse.h"
#include "x11_client_key.h"
#include "x11_client_window.h"

void Init_x11_client_ext() {
  eX11ClientError = rb_define_class("X11ClientError", rb_eStandardError);

  cX11Client = rb_define_class("X11Client", rb_cObject);

  rb_define_alloc_func(cX11Client, X11Client_alloc);
  rb_define_method(cX11Client, "initialize", X11Client_initialize, 1);

  rb_define_method(cX11Client, "open_display", X11Client_open_display, 0);
  rb_define_method(cX11Client, "close_display", X11Client_close_display, 0);
  rb_define_method(cX11Client, "sync", X11Client_sync, 0);

  rb_define_method(cX11Client, "start", X11Client_start, 0);
  rb_define_method(cX11Client, "stop", X11Client_stop, 0);

  rb_define_method(cX11Client, "root_window_id", X11Client_root_window_id, 0);
  rb_define_method(cX11Client, "window_children_ids", X11Client_window_children_ids, 1);
  rb_define_method(cX11Client, "get_window", X11Client_get_window, 1);
  rb_define_method(cX11Client, "get_window_name", X11Client_get_window_name, 1);

  rb_define_method(cX11Client, "mousemove", X11Client_mousemove, 2);
  rb_define_method(cX11Client, "mousedown", X11Client_mousedown, 1);
  rb_define_method(cX11Client, "mouseup", X11Client_mouseup, 1);
  rb_define_method(cX11Client, "mouseclick", X11Client_mouseclick, 1);

  rb_define_method(cX11Client, "keydown", X11Client_keydown, 1);
  rb_define_method(cX11Client, "keyup", X11Client_keyup, 1);
  rb_define_method(cX11Client, "keypress", X11Client_keypress, 1);
}
