# ⚡ Classical Buck DC-DC Converter (30V → 15V, 30W, 50kHz)

> Mini Project — BEEE301L Power Electronics | VIT Chennai | Winter Semester 2025-26  
> Faculty: Dr. M. Prabhakar | Batch No: 19

---

## 📌 Overview

A classical Buck (step-down) DC-DC converter designed to convert a 30V input to a regulated 15V output at 30W, switching at 50kHz. The project covers the complete design flow — from mathematical design and MATLAB/Simulink simulation to PCB fabrication using KiCad.

---

## ⚙️ Technical Specifications

| Parameter | Value |
|-----------|-------|
| Input Voltage | 30 V |
| Output Voltage | 15 V |
| Output Power | 30 W |
| Output Current | 2 A |
| Switching Frequency | 50 kHz |
| Duty Cycle | 0.5 |
| Operating Mode | Continuous Conduction Mode (CCM) |

---

## 🔩 Components

| Component | Part Number | Rating |
|-----------|-------------|--------|
| MOSFET (Switch) | IRF540N | 100V, 33A |
| Diode (Freewheeling) | MBR1060 | 60V, 10A |
| Gate Driver | TLP250 | Opto-isolated |
| Inductor | Coilcraft RFB0810-221L | 220 µH |
| Output Capacitor | Nichicon UPM1E100MHD | 10 µF / 25V |
| Load Resistance | — | 7.5 Ω |
| PWM Source | Arduino | 50kHz PWM |

---

## 📐 Design Equations

**Duty Cycle:**
```
D = Vout / Vin = 15 / 30 = 0.5
```

**Inductor value (CCM):**
```
L = (Vin - Vout) × D / (ΔiL × f)
  = (30 - 15) × 0.5 / (ΔiL × 50000)
  → Selected: 220 µH
```

**Output Capacitor:**
```
C = ΔiL / (8 × f × ΔVout)
  → Selected: 10 µF
```

---

## 💻 MATLAB/Simulink Simulation

The circuit was simulated in MATLAB/Simulink to verify:
- Output voltage regulation at 15V
- Inductor current waveform in CCM
- Output voltage ripple
- MOSFET switching behaviour

📁 Simulation files are in the `/simulation` folder.

**To run:**
1. Open MATLAB (R2023a or later recommended)
2. Open `buck_converter_simulation.slx` in Simulink
3. Run the simulation (Ctrl+T)
4. View output voltage and inductor current on the scope blocks

---

## 🖥️ PCB Design (KiCad 9.0)

The PCB was designed using KiCad 9.0 with attention to:
- Power trace width (calculated for 2A current)
- Ground plane for noise reduction
- Component placement for thermal management
- Short gate drive traces to minimize switching noise

📁 KiCad project files are in the `/pcb` folder.

**Files included:**
- `buck_converter.kicad_pro` — Project file
- `buck_converter.kicad_sch` — Schematic
- `buck_converter.kicad_pcb` — PCB layout
- `gerber/` — Gerber files for fabrication

**PCB Status:** Fabricated ✅ | Tested ❌ (pending)

---

## 🔌 Arduino PWM Gate Drive

The 50kHz PWM signal for the gate driver is generated using Arduino:

```cpp
// Buck Converter Gate Drive — 50kHz PWM
// Arduino generates PWM on pin 9

void setup() {
  // Set Timer1 for 50kHz fast PWM on pin 9
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10); // No prescaler
  ICR1 = 319;        // 16MHz / 50kHz - 1 = 319
  OCR1A = 159;       // 50% duty cycle (319 / 2 = ~159)
}

void loop() {
  // PWM runs automatically via Timer1
}
```

---

## 📁 Repository Structure

```
buck-dc-dc-converter/
├── README.md
├── simulation/
│   ├── buck_converter_simulation.slx    ← MATLAB/Simulink model
│   └── simulation_results/
│       ├── output_voltage.png
│       └── inductor_current.png
├── pcb/
│   ├── buck_converter.kicad_pro
│   ├── buck_converter.kicad_sch
│   ├── buck_converter.kicad_pcb
│   └── gerber/
├── arduino/
│   └── pwm_gate_drive.ino
└── docs/
    └── project_report.pdf
```

---

## 📚 Key Learnings

- Buck converter operation in Continuous Conduction Mode (CCM)
- How duty cycle controls output voltage in DC-DC converters
- Inductor and capacitor design using standard equations
- MOSFET switching behaviour and freewheeling diode operation
- PCB design considerations for power electronics circuits
- PWM signal generation using Arduino Timer registers

---

## 👥 Team

| Name | Register No. |
|------|-------------|
| Sanjay Kumar G | 24BEE1256 |
| Selva Krishna SJ | 24BEE1017 |

---

## 👨‍💻 Author

**Sanjay Kumar G** | B.Tech EEE, VIT Chennai  
[LinkedIn](https://www.linkedin.com/in/sanjay-kumar-g-933073333) · [GitHub](https://github.com/gsanjaykumar26sk-eng) · gsanjaykumar26sk@gmail.com
