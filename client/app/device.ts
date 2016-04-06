export class Device {
    public temperature: number;
    public lightSensor: number;
    public humidity: number;

    constructor() {
        this.temperature = 0.0;
        this.lightSensor = 0.0;
        this.humidity = 0.0;
    }
}
