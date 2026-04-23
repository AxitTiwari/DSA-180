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

# Prepare smooth curves
smooth_data = {}
for name, values in data.items():
    x_smooth = np.linspace(x.min(), x.max(), 300)
    spline = make_interp_spline(x, values, k=3)
    y_smooth = spline(x_smooth)
    smooth_data[name] = (x_smooth, y_smooth)

# Create empty lines
lines = {}
for name in data.keys():
    line, = ax.plot([], [], color=colors[name], linewidth=3 if name=="Axit" else 2)
    lines[name] = line

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

# Animation function
def update(frame):
    for name, (xs, ys) in smooth_data.items():
        lines[name].set_data(xs[:frame], ys[:frame])
    return lines.values()

# Create animation
ani = FuncAnimation(
    fig,
    update,
    frames=300,
    interval=20,
    blit=True
)

plt.tight_layout()
plt.show()


# import matplotlib.pyplot as plt
# from matplotlib.animation import FuncAnimation

# dates = [
#     "31-03", "01-04", "02-04", "03-04", "04-04",
#     "05-04", "06-04", "07-04", "08-04", "09-04",
#     "10-04", "11-04"
# ]

# data = {
#     "Axit": [142, 144, 149, 157, 158, 161, 166, 167, 168, 169, 171, 176],
#     "Shikhar": [95, 98, 98, 99, 99, 103, 107, 108, 109, 110, 111, 112],
#     "Arpit": [125, 125, 128, 131, 141, 145, 147, 148, 149, 150, 153, 154],
#     "Yash": [123, 123, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126],
#     "Divyanshu": [65, 69, 70, 71, 71, 73, 74, 78, 79, 81, 83, 87]
# }

# names = list(data.keys())

# fig, ax = plt.subplots(figsize=(10, 6))

# def update(frame):
#     ax.clear()

#     # Get values for this day
#     current = {name: data[name][frame] for name in names}

#     # Sort by score
#     sorted_data = sorted(current.items(), key=lambda x: x[1])

#     names_sorted = [x[0] for x in sorted_data]
#     values_sorted = [x[1] for x in sorted_data]

#     ax.barh(names_sorted, values_sorted)

#     ax.set_title(f"🏆 Ranking on {dates[frame]}")
#     ax.set_xlabel("Total Questions")

#     for i, v in enumerate(values_sorted):
#         ax.text(v + 1, i, str(v))

# ani = FuncAnimation(fig, update, frames=len(dates), interval=800)
# plt.show()