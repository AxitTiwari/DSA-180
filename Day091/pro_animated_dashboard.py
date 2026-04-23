
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline
from matplotlib.animation import FuncAnimation
import threading
import sys

# Optional sound (works on Windows)
def play_tick():
    try:
        import winsound
        winsound.Beep(800, 30)
    except:
        pass

# Data
dates = [
    "31-03","01-04","02-04","03-04","04-04",
    "05-04","06-04","07-04","08-04","09-04",
    "10-04","11-04","12-04","13-04","14-04"
]

x = np.arange(len(dates))

data = {
    "Axit": [142,144,149,157,158,161,166,167,168,169,171,176,183,187,190],
    "Shikhar": [95,98,98,99,99,103,107,108,109,110,111,112,113,115,116],
    "Arpit": [125,125,128,131,141,145,147,148,149,150,153,154,156,158,163],
    "Yash": [123,123,126,126,126,126,126,126,126,126,126,126,130,130,133],
    "Divyanshu": [65,69,70,71,71,73,74,78,79,81,83,87,90,91,91]
}

colors = {
    "Axit":"#1f77b4","Shikhar":"#ff7f0e","Arpit":"#2ca02c",
    "Yash":"#d62728","Divyanshu":"#9467bd"
}

plt.style.use('seaborn-v0_8-whitegrid')
fig, ax = plt.subplots(figsize=(12,7))

# Smooth curves
smooth = {}
for k,v in data.items():
    xs = np.linspace(x.min(), x.max(), 300)
    ys = make_interp_spline(x,v)(xs)
    smooth[k]=(xs,ys)

lines,points,labels={}, {}, {}

for k in data:
    l,=ax.plot([],[],color=colors[k],lw=3 if k=="Axit" else 2)
    p,=ax.plot([],[],'o',color=colors[k])
    t=ax.text(0,0,"",color=colors[k],fontsize=10,weight='bold')
    lines[k],points[k],labels[k]=l,p,t

rank_text = ax.text(0.02,0.85,"",transform=ax.transAxes,fontsize=12,weight='bold')

# Prediction (linear regression)
pred_lines={}
for k,v in data.items():
    coef = np.polyfit(x,v,1)
    future_x = np.arange(len(x)+5)
    future_y = coef[0]*future_x + coef[1]
    pred_line,=ax.plot([],[],'--',alpha=0.4,color=colors[k])
    pred_lines[k]=(future_x,future_y,pred_line)

ax.set_xticks(x)
ax.set_xticklabels(dates,rotation=30)
ax.set_xlim(x.min(),x.max()+3)
ax.set_ylim(60,210)

def update(frame):
    idx=min(int(frame/20),len(x)-1)

    # ranking
    current = {k:data[k][idx] for k in data}
    ranked = sorted(current.items(), key=lambda x: x[1], reverse=True)
    rank_str="\\n".join([f"{i+1}. {name}" for i,(name,_) in enumerate(ranked)])
    rank_text.set_text(rank_str)

    for k,(xs,ys) in smooth.items():
        lines[k].set_data(xs[:frame],ys[:frame])
        if frame>0:
            xv=xs[frame-1]; yv=ys[frame-1]
            points[k].set_data([xv],[yv])
            labels[k].set_position((xv+0.1,yv))
            labels[k].set_text(k)

        # prediction after full draw
        if frame>250:
            fx,fy,pl = pred_lines[k]
            pl.set_data(fx,fy)

    # sound
    if frame%15==0:
        threading.Thread(target=play_tick).start()

    return list(lines.values())+list(points.values())+list(labels.values())

ani=FuncAnimation(fig,update,frames=300,interval=30,blit=True)

# Save MP4 (requires ffmpeg installed)
try:
    ani.save("coding_progress.mp4", writer='ffmpeg', fps=30)
    print("MP4 saved as coding_progress.mp4")
except:
    print("MP4 export failed (install ffmpeg).")

plt.tight_layout()
plt.show()

# -------- Optional GUI --------
if "--gui" in sys.argv:
    import tkinter as tk
    root=tk.Tk()
    root.title("Coding Progress Dashboard")
    label=tk.Label(root,text="Run animation separately. This is GUI placeholder.",font=("Arial",14))
    label.pack(padx=20,pady=20)
    root.mainloop()
