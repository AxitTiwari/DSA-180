import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from matplotlib.animation import FuncAnimation

# Data
data = {
    "Date": ["31-03-2026","01-04-2026","02-04-2026","03-04-2026","04-04-2026","05-04-2026"],
    "Axit": [142,144,149,157,158,161],
    "Shikhar": [95,98,98,99,99,103],
    "Arpit": [125,125,128,131,141,145],
    "Yash": [123,123,126,126,126,126],
    "Divyanshu": [65,69,70,71,71,73]
}

df = pd.DataFrame(data)

fig, ax = plt.subplots(figsize=(8,5))
x = np.arange(len(df))

def update(frame):
    ax.clear()
    
    values = {name: df[name][frame] for name in df.columns[1:]}
    sorted_players = sorted(values.items(), key=lambda x: x[1], reverse=True)

    names = [p[0] for p in sorted_players]
    scores = [p[1] for p in sorted_players]

    ax.barh(names, scores)
    
    for i, (name, score) in enumerate(sorted_players):
        ax.text(score + 1, i, f"{score}", va='center')

    ax.set_title(f"Leaderboard - {df['Date'][frame]}")
    ax.invert_yaxis()

ani = FuncAnimation(fig, update, frames=len(df), interval=800)

# Save as GIF (NO extra setup needed)
ani.save("leaderboard.gif")

plt.show()