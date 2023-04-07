#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printer.h"
#include "my_queue.h"

void init_printer(Printer* printer, const char* manufacturer, PaperFormat paper_format, int printing_speed) {
    strncpy(printer->manufacturer, manufacturer, sizeof(printer->manufacturer) - 1);
    printer->manufacturer[sizeof(printer->manufacturer) - 1] = '\0';
    printer->paper_format = paper_format;
    printer->printing_speed = printing_speed;
}

void print_printer_info(const Printer* printer) {
    printf("Manufacturer: %s\n", printer->manufacturer);
    printf("Paper format: %s\n", printer->paper_format == A3 ? "A3" : "A4");
    printf("Printing speed: %d pages per minute\n", printer->printing_speed);
}

int main() {
    Queue queue = { NULL, NULL };

    for (int i = 0; i < 5; ++i) {
        Printer* printer = (Printer*)malloc(sizeof(Printer));
        init_printer(printer, "Some Manufacturer", A4, 20 + i * 5);
        enqueue(&queue, printer);
    }

    for (int i = 0; i < 3; ++i) {
        Printer* printer = dequeue(&queue);
        if (printer) {
            printf("Printer %d:\n", i + 1);
            print_printer_info(printer);
            printf("\n");
            free(printer);
        }
    }

    delete_queue(&queue);

    return 0;
}
