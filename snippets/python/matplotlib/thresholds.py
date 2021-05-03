import numpy as np
import matplotlib.pyplot as plt

warning_limit = 75
failure_limit = 100

warning_colour='orange'
failure_colour='red'

# original_array = np.random.rand(1000)
# original_array = np.arange(150)
original_array = np.array([1,5,25,70,80,85,60,120,190,110,120,5])

# Get array of normal values that is below the warning and failure limits.
normal_array = np.ma.masked_greater_equal(original_array, warning_limit)

# Get array of warnings and failures.
warning_and_failure_array = np.ma.masked_less_equal(original_array, warning_limit)

# Split array into individual warning and failure arrays.
failure_array = np.ma.masked_less_equal(warning_and_failure_array, failure_limit)
warning_array = np.ma.masked_greater_equal(warning_and_failure_array, failure_limit)

# Plot full line.
plt.plot(original_array, 'black')

# Plot individual warning and failure arrays on top.
plt.plot(warning_array, warning_colour, linewidth=2)
plt.plot(failure_array, failure_colour, linewidth=2)

# add the threshold value (optional)
plt.axhline(warning_limit, color=warning_colour, linestyle='--')
plt.axhline(failure_limit, color=failure_colour, linestyle='--')
plt.show()
