#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
void set_wallpaper(const char *path) {
  SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void *)path,
                        SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
}
#elif __linux__
void set_wallpaper(const char *path) {
  char command[512];
  snprintf(command, sizeof(command),
           "gsettings set org.gnome.desktop.background picture-uri 'file://%s'",
           path);
  system(command);
}
#elif __APPLE__
void set_wallpaper(const char *path) {
  char command[512];
  snprintf(command, sizeof(command),
           "osascript -e 'tell application \"Finder\" to set desktop picture "
           "to POSIX file \"%s\"'",
           path);
  system(command);
}
#else
void set_wallpaper(const char *path) { printf("OS not supported.\n"); }
#endif

// File chooser dialog
void on_file_selected(GtkWidget *widget, gpointer data) {
  GtkWidget *dialog = gtk_file_chooser_dialog_new(
      "Choose Wallpaper", GTK_WINDOW(data), GTK_FILE_CHOOSER_ACTION_OPEN,
      "Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);

  if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
    char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    set_wallpaper(filename);
    g_free(filename);
  }
  gtk_widget_destroy(dialog);
}

// Main function
int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Wallpaper Switcher");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  GtkWidget *button = gtk_button_new_with_label("Choose Wallpaper");
  g_signal_connect(button, "clicked", G_CALLBACK(on_file_selected), window);

  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 10);
  gtk_container_add(GTK_CONTAINER(window), box);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
