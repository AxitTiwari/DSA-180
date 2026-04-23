
import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline
from matplotlib.animation import FuncAnimation

plt.style.use('seaborn-v0_8-whitegrid')

dates = [
    "31-03", "01-04", "02-04", "03-04", "04-04",
    "05-04", "06-04", "07-04", "08-04", "09-04",
    "10-04", "11-04", "12-04", "13-04", "14-04"
]

x = np.arange(len(dates))

data = {
    "Axit": [142, 144, 149, 157, 158, 161, 166, 167, 168, 169, 171, 176, 183, 187, 190],
    "Shikhar": [95, 98, 98, 99, 99, 103, 107, 108, 109, 110, 111, 112, 113, 115, 116],
    "Arpit": [125, 125, 128, 131, 141, 145, 147, 148, 149, 150, 153, 154, 156, 158, 163],
    "Yash": [123, 123, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 130, 130, 133],
    "Divyanshu": [65, 69, 70, 71, 71, 73, 74, 78, 79, 81, 83, 87, 90, 91, 91]
}

colors = {
    "Axit": "#1f77b4",
    "Shikhar": "#ff7f0e",
    "Arpit": "#2ca02c",
    "Yash": "#d62728",
    "Divyanshu": "#9467bd"
}

fig, ax = plt.subplots(figsize=(12, 7))

# Smooth curves
smooth_data = {}
for name, values in data.items():
    x_smooth = np.linspace(x.min(), x.max(), 300)
    spline = make_interp_spline(x, values, k=3)
    y_smooth = spline(x_smooth)
    smooth_data[name] = (x_smooth, y_smooth)

# Lines, markers, and labels
lines = {}
points = {}
labels = {}

for name in data.keys():
    line, = ax.plot([], [], linewidth=3 if name=="Axit" else 2)
    point, = ax.plot([], [], 'o')
    label = ax.text(0, 0, "", fontsize=10, weight='bold')

    line.set_color(colors[name])
    point.set_color(colors[name])
    label.set_color(colors[name])

    lines[name] = line
    points[name] = point
    labels[name] = label

# Axis setup
ax.set_xticks(x)
ax.set_xticklabels(dates, rotation=30)
ax.set_xlim(x.min(), x.max())
ax.set_ylim(60, 200)

ax.set_title("📈 Coding Progress Animation", fontsize=16, weight='bold')
ax.set_xlabel("Date")
ax.set_ylabel("Total Questions Solved")

for spine in ["top", "right"]:
    ax.spines[spine].set_visible(False)

# Annotation for daily values
day_text = ax.text(0.02, 0.95, "", transform=ax.transAxes, fontsize=12, weight='bold')

# Animation function
def update(frame):
    for name, (xs, ys) in smooth_data.items():
        lines[name].set_data(xs[:frame], ys[:frame])

        if frame > 0:
            x_val = xs[frame-1]
            y_val = ys[frame-1]
            points[name].set_data([x_val], [y_val])

            labels[name].set_position((x_val + 0.1, y_val))
            labels[name].set_text(name)

    # Show day info
    idx = int(frame / 20) if frame < 300 else len(x)-1
    if idx < len(x):
        text = f"{dates[idx]}:\n"
        for name in data:
            text += f"{name}: {data[name][idx]}  "
        day_text.set_text(text)

    return list(lines.values()) + list(points.values()) + list(labels.values())

ani = FuncAnimation(
    fig,
    update,
    frames=300,
    interval=20,
    blit=True
)

plt.tight_layout()
plt.show()

# Optional: save animation as GIF (uncomment if needed)
ani.save("coding_progress.gif", writer='pillow', fps=30)
