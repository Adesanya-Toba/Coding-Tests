#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

#define RS485 0
#define RS232 1
#define CAN 2

void arrayPrint(int* array)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main ()
{
    config_t cfg;
    config_setting_t *setting;
    const char* str;

    config_init(&cfg);

    /* Read the file. If there is an error, report it and exit. */
    if (!config_read_file(&cfg, "my_config.cfg")){
        fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
        config_error_line(&cfg), config_error_text(&cfg));
        config_destroy(&cfg);
        return(EXIT_FAILURE);
    }

    /* Get device name */
    if (config_lookup_string(&cfg, "Device", &str))
        printf("Device name: %s\n", str);
    else
    {
        fprintf(stderr, "No 'Device' setting found in configuration file\n");
    }
    
    /* Print out comms information */
    setting = config_lookup(&cfg, "Config.Comm_scheme");
    if(setting != NULL)
    {
        int length = config_setting_length(setting);
        printf("Comm scheme length: %d\n", length);
        int comms_config[10];
        int count = 0;

        config_setting_t *comm_scheme = config_setting_get_elem(setting, RS485);
        config_setting_lookup_int(comm_scheme, "port", &comms_config[count++]);
        config_setting_lookup_int(comm_scheme, "slave_address", &comms_config[count++]);
        config_setting_lookup_int(comm_scheme, "baudrate", &comms_config[count++]);
        config_setting_lookup_int(comm_scheme, "buffer_size", &comms_config[count++]);
        config_setting_lookup_int(comm_scheme, "starting_address", &comms_config[count++]);
        config_setting_lookup_int(comm_scheme, "no_of_addresses", &comms_config[count++]);
        printf("Port number: %d\n", comms_config[0]);
        printf("Slave addr: %d\n", comms_config[1]);
        printf("Baudrate: %d\n", comms_config[2]);
        printf("Buffer size: %d\n", comms_config[3]);
        printf("Starting address: %d\n", comms_config[4]);
        printf("No of addresses to read: %d\n", comms_config[5]);

    }
}
