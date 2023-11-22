def bouncing_ball(h: float, bounce: float, window: float) -> int:
    if (h <= 0.0 or h <= window) or (bounce <= 0.0 or bounce >= 1.0):
        return -1
    count = int(1)
    next_pos = h * bounce
    while (next_pos > window):
        next_pos *= bounce
        count += 2
    return count


print(bouncing_ball(3.0, 0.66, 1.5))
print(bouncing_ball(3.0, 1, 1.5))
