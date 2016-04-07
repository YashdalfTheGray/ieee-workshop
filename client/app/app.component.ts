import { Component, OnInit } from 'angular2/core';
import { Response } from 'angular2/http';

import { ParticleService } from './particle.service';
import { Device } from './device.types';

@Component({
    selector: 'ieee-app',
    templateUrl: 'app/app.tpl.html',
    providers: [
        ParticleService
    ]
})
export class AppComponent implements OnInit {
    private res: Array<Device>;
    constructor(public particleService: ParticleService) {}

    ngOnInit() {
        this.particleService.getDevices().subscribe((res: Response) => {
            this.res = res.json();
            this.res.forEach(device => {
                device.variables = {};
                ['temperature', 'lightSensor', 'humidity'].forEach((sensor: string) => {
                    this.particleService.getVariable(device.id, sensor).subscribe((res: Response) => {
                        var sensorResponse = res.json();
                        device.variables[sensorResponse.name] = sensorResponse.result;
                    });
                });
            });
        });
    }
}
