#include "usb.h"
#include"cdc.h"
#include "usbd_core.h"     // USBD_Init, USBD_RegisterClass, USBD_Start
#include "usbd_def.h"
#include "usbd_desc.h"     // FS_Desc

#if HW_USE_CDC ==1
#include "usbd_cdc.h"      // USBD_CDC
#include "usbd_cdc_if.h"   // USBD_Interface_fops_FS, CDC_Transmit_FS
#endif

#if HW_USE_MSC ==1
#include "usbd_msc.h"
#include "usbd_storage_if.h"
#endif

#ifdef _USE_HW_USB

#include "usb_device.h"

static bool is_init = false;
static UsbMode is_usb_mode = USB_NON_MODE;

USBD_HandleTypeDef hUsbDeviceFS;

extern USBD_DescriptorsTypeDef CDC_Desc;
extern USBD_DescriptorsTypeDef MSC_Desc;

bool usbInit(void){
    bool ret = true;

    return ret;
}

void usbDeInit(void){

}

UsbMode usbGetMode(void){

    return is_usb_mode;
}

bool usbBegin(UsbMode usb_mode){
    bool ret = false;
    #if HW_USE_CDC == 1
    if(usb_mode == USB_CDC_MODE){
        /* USER CODE BEGIN USB_DEVICE_Init_PreTreatment */

        /* USER CODE END USB_DEVICE_Init_PreTreatment */

        /* Init Device Library, add supported class and start the library. */
        if (USBD_Init(&hUsbDeviceFS, &CDC_Desc, DEVICE_FS) != USBD_OK)
        {
           return false;
        }
        if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_CDC) != USBD_OK)
        {
           return false;
        }
        if (USBD_CDC_RegisterInterface(&hUsbDeviceFS, &USBD_Interface_fops_FS) != USBD_OK)
        {
           
           return false;
        }
        if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
        {
           return false;
        }

        cdcInit();
        ret = true;
        is_usb_mode = USB_CDC_MODE;   
    }
    #endif

    #if HW_USE_MSC ==1
    if(usb_mode == USB_MSC_MODE)
        {
        if (USBD_Init(&hUsbDeviceFS, &MSC_Desc, DEVICE_FS) != USBD_OK)
        {
            return false;
        }
        if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_MSC) != USBD_OK)
        {
            return false;
        }
        if (USBD_MSC_RegisterStorage(&hUsbDeviceFS, &USBD_Storage_Interface_fops_FS) != USBD_OK)
        {
                return false;
        }
        if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
        {
            return false;
        }
        ret = true;
        is_usb_mode = USB_MSC_MODE;   
        }
    #endif
    
    
    is_init = ret;
    return ret;
}
#endif