import hid

vendor_id     = 0x1209  # Vendor ID supplied by https://pid.codes
product_id    = 0x2211  # Unique Mathpad product ID

usage_page    = 0xFF60 # QMK Standard
usage         = 0x61   # QMK Standard
report_length = 32     # QMK Standard

def get_raw_hid_interface():
    device_interfaces = hid.enumerate(vendor_id, product_id)
    raw_hid_interfaces = [i for i in device_interfaces if i['usage_page'] == usage_page and i['usage'] == usage]

    if len(raw_hid_interfaces) == 0:
        return None

    interface = hid.Device(path=raw_hid_interfaces[0]['path'])

    print(f"Manufacturer: {interface.manufacturer}")
    print(f"Product: {interface.product}")

    return interface

if __name__ == '__main__':
    interface = get_raw_hid_interface()
    while True:
        response = interface.read(report_length, timeout=1000)
        if response:
            print(response)