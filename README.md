#  Classical Buck DC-DC Converter (30V → 15V, 30W, 50kHz)

> Mini Project — BEEE301L Power Electronics | VIT Chennai | Winter Semester 2025-26
> Faculty: Dr. M. Prabhakar 

---

## Overview

A classical Buck (step-down) DC-DC converter designed to convert a 30V input to a regulated 15V output at 30W, switching at 50kHz. The project covers the complete design flow — mathematical design, MATLAB/Simulink simulation, LTspice verification, and PCB fabrication using KiCad 9.0.

---

##  Specifications

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

##  Components

| Component | Part | Rating |
|-----------|------|--------|
| MOSFET | IRF540N | 100V, 33A |
| Diode | MBR1060 | 60V, 10A |
| Gate Driver | TLP250 | Opto-isolated |
| Inductor | Coilcraft RFB0810-221L | 220 µH |
| Capacitor | Nichicon UPM1E100MHD | 10 µF / 25V |
| Load | — | 7.5 Ω |
| PWM Source | Arduino | 50kHz via Timer1 |

---

##  Design Equations

```
Duty Cycle:   D = Vout / Vin = 15 / 30 = 0.5

Inductor:     L = (Vin - Vout) × D / (ΔiL × f)  →  220 µH selected

Capacitor:    C = ΔiL / (8 × f × ΔVout)  →  10 µF selected
```

---

##  Simulation

Simulated in **MATLAB/Simulink** and **LTspice** to verify:
- Output voltage regulation at 15V
- Inductor current waveform in CCM
- Output voltage ripple under load
- MOSFET switching transitions

 Simulation files → `/simulation/`

**To run MATLAB/Simulink model:**
1. Open MATLAB (R2023a or later)
2. Open `buck_converter_simulation.slx`
3. Run simulation (Ctrl+T) and view scope blocks

---

##  PCB Design (KiCad 9.0)

Designed with attention to:
- Power trace width calculated for 2A
- Ground plane for noise reduction
- Short gate drive traces to minimise switching noise
- Component placement for thermal management

 KiCad files → `/pcb/`

**PCB status:** Fabricated  | Tested  (pending)

---

##  Arduino PWM Gate Drive

```cpp
// 50kHz PWM via Timer1 on Pin 9
// 16MHz / (1 × (319+1)) = 50kHz

void setup() {
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
  ICR1  = 319;   // Sets 50kHz
  OCR1A = 159;   // 50% duty cycle
}

void loop() { } // Timer1 runs autonomously
```

---

##  Repository Structure

```
buck-dc-dc-converter/
├── README.md
├── simulation/
│   ├── buck_converter_simulation.slx   ← MATLAB/Simulink
│   └── buck_converter.asc              ← LTspice
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

##  Key Learnings

- Buck converter operation in CCM and duty cycle control
- Inductor and capacitor design from equations
- MATLAB/Simulink and LTspice simulation workflows
- PCB design: trace width, ground planes, layout for power electronics
- Timer register programming in Arduino for precise PWM

---

##  Team

| Name | Reg. No. |
|------|----------|
| Sanjay Kumar G | 24BEE1256 |
| Selva Krishna SJ | 24BEE1017 |

---

**Sanjay Kumar G** · B.Tech EEE, VIT Chennai  
[LinkedIn](https://www.linkedin.com/in/sanjay-kumar-g-933073333) · [GitHub](https://github.com/gsanjaykumar26sk-eng)
