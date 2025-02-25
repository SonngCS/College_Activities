import tkinter as tk
import playsound as ps
import threading


def NuttingWithThreads():
    t1 = threading.Thread(target=Nutting)
    t1.start()

def Nutting():
    ps.playsound('Nuts.mp3')
    

def Window():
    window = tk.Tk()

    window.title("Deez Nuts button")
    window.geometry('600x400')

    button = tk.Button(window, text="Deez Nuts", command=NuttingWithThreads)
    button.pack(pady=150)

    window.mainloop()

def main():

    Window()

if __name__ == '__main__':
    main()