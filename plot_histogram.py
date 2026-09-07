"""Plot a grayscale histogram exported by the C++ application."""

import csv
import sys
from pathlib import Path

import matplotlib.pyplot as plt


def read_histogram(csv_path: Path) -> tuple[list[int], list[int]]:
    intensities: list[int] = []
    frequencies: list[int] = []

    with csv_path.open(newline="", encoding="utf-8") as csv_file:
        for row in csv.DictReader(csv_file):
            intensities.append(int(row["intensity"]))
            frequencies.append(int(row["frequency"]))

    return intensities, frequencies


def main() -> int:
    if len(sys.argv) != 2:
        print(f"Usage: {Path(sys.argv[0]).name} <histogram.csv>")
        return 1

    csv_path = Path(sys.argv[1])
    if not csv_path.is_file():
        print(f"Could not open histogram file: {csv_path}")
        return 1

    intensities, frequencies = read_histogram(csv_path)
    output_path = csv_path.with_suffix(".png")

    plt.figure(figsize=(10, 5))
    plt.plot(intensities, frequencies, color="black", linewidth=1)
    plt.xlim(0, 255)
    plt.xlabel("Intensity level (0-255)")
    plt.ylabel("Pixel frequency")
    plt.title(f"Grayscale histogram - {csv_path.stem}")
    plt.xticks(range(0, 256, 25))
    plt.grid(axis="y", alpha=0.25)
    plt.tight_layout()
    plt.savefig(output_path, dpi=150)
    plt.close()

    print(f"Histogram image exported to: {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
