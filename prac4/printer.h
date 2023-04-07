#ifndef PRINTER_H
#define PRINTER_H

typedef enum {
    A3,
    A4
} PaperFormat;

typedef struct {
    char manufacturer[50];
    PaperFormat paper_format;
    int printing_speed;
} Printer;

void init_printer(Printer* printer, const char* manufacturer, PaperFormat paper_format, int printing_speed);
void print_printer_info(const Printer* printer);

#endif // PRINTER_H

