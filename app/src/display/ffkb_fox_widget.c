#include "ffkb_fox_widget.h"

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

// const void* *images;
// uint8_t images_len;

LV_IMG_DECLARE(fox_mid);
LV_IMG_DECLARE(fox_down);
LV_IMG_DECLARE(fox_bot);
LV_IMG_DECLARE(fox_up);

const void* images[] = {
    &fox_mid,
    &fox_down,
    &fox_bot,
    &fox_up
};

void set_img_src(void *var, lv_anim_value_t val) {
    lv_obj_t *img = (lv_obj_t *)var;
    lv_img_set_src(img, images[val]);
}

int ffkb_fox_widget_init(struct ffkb_fox_widget *widget, lv_obj_t *parent) {
    widget->obj = lv_img_create(parent, NULL);
    lv_img_set_auto_size(widget->obj, true);
    // lv_img_set_src(widget->obj, &fox_mid);
    // lv_obj_align(widget->obj, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_anim_init(&widget->anim);
    lv_anim_set_time(&widget->anim, 1000);
    // lv_anim_set_repeat_delay(&widget->anim, 500);
    lv_anim_set_var(&widget->anim, widget->obj);
    lv_anim_set_values(&widget->anim, 0, 3);
    lv_anim_set_exec_cb(&widget->anim, set_img_src);
    lv_anim_set_repeat_count(&widget->anim, LV_ANIM_REPEAT_INFINITE);

    lv_anim_start(&widget->anim);

    return 0;
}

lv_obj_t *ffkb_fox_widget_obj(struct ffkb_fox_widget *widget) { return widget->obj; }
