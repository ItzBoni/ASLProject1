First midterm project for image processing class

## Histogram workflow

The C++ program exports one CSV file per image from `main`, for example
`histogram_1.csv`. Install Matplotlib and generate the labeled histogram with:

```text
python3 -m pip install matplotlib
python3 plot_histogram.py histogram_1.csv
```

The script creates `histogram_1.png` beside the CSV. The original image
dimensions are not changed; only the histogram is generated from the exported
intensity frequencies.
