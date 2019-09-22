from tkinter import *



# Colors
darkish = '#%02x%02x%02x' % (29, 30, 38)
whitish = '#%02x%02x%02x' % (214, 216, 218)
code_green = '#%02x%02x%02x' % (80, 200, 70)
code_green_light = '#%02x%02x%02x' % (170, 200, 150)
code_dark = '#%02x%02x%02x' % (23, 24, 30)

root = Tk()
root.configure(bg=darkish)

root.title("BlueOrigin FlightSim")

# display everything
top = root.winfo_toplevel()
menuBar = Menu(top)
top['menu'] = menuBar
subMenu = Menu(menuBar)
portMenu = Menu(menuBar)

w = Label(root, text="Blue Origin Flight Simulator", font='Helvetica 20 bold', bg=darkish, fg=whitish).grid(row=0, column=0, columnspan=6, padx=10)

text_packet = Label(text="", bg=darkish, fg=whitish).grid(row=18, column=4)

progress = ttk.Progressbar(root, orient=HORIZONTAL, length=600, mode='determinate')
progress.grid(row=8, column=4)
#progress.start()
progress['value'] = 30

packet_title = Label(text="Text Packet:", font ='Helvetica 18 bold', bg=darkish, fg=whitish).grid(row=11, column=4)
restart = Button(root, text="Restart", font='Helvetica 15 bold', bg=darkish, highlightbackground=darkish, highlightthickness=30, foreground=whitish).grid(row=0, column=5)

arduinoOutput = Label(text="Arduino Output   \n", font='Helvetica 18 bold', bg=darkish, fg=whitish).grid(row=19, column=4)

