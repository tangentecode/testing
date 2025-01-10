from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QPushButton, QLabel, QComboBox
from PyQt6.QtCore import Qt
import sys

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.initialize_ui()
        self.add_widgets()
        self.show()
    
    def initialize_ui(self):
        self.setGeometry(300, 300, 700, 700)
        self.setWindowTitle("Just a test")
        self.main_layout = QVBoxLayout()
        self.setLayout(self.main_layout)
        

    
    def add_widgets(self):
        self.label = QLabel("Example Text")
        self.label.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.button = QPushButton()
        self.button.clicked.connect(lambda: print(f"[LOG] Button pushed"))
        self.button.clicked.connect(self.show_button_input)

        self.dropdown = QComboBox()
        self.dropdown.addItems(["", "Option 1", "Option 2", "Option 3", "Option 4"])
        self.dropdown.currentIndexChanged.connect(self.show_dropdown_input)
        self.dropdown.currentIndexChanged.connect(lambda index: print(f"[LOG] {self.dropdown.itemText(index)} selected"))
       
        
        self.action = QLabel("")
        self.action.setAlignment(Qt.AlignmentFlag.AlignCenter)
    
        self.main_layout.addWidget(self.label)
        self.main_layout.addWidget(self.button)
        self.main_layout.addWidget(self.dropdown)
        self.main_layout.addWidget(self.action)

    def show_button_input(self):
        self.action.setText("Button clicked")

    def show_dropdown_input(self, index):
        self.action.setText(f"{self.dropdown.itemText(index)} selected")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    sys.exit(app.exec())
