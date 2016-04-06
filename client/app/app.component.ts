import { Component, OnInit } from 'angular2/core';
import { Response } from 'angular2/http';

import { ParticleService } from './particle.service';

@Component({
    selector: 'ieee-app',
    templateUrl: 'app/app.tpl.html',
    providers: [
        ParticleService
    ]
})
export class AppComponent implements OnInit {
    private res: Array<Object>;
    constructor(public particleService: ParticleService) {}

    ngOnInit() {
        this.particleService.getDevices().subscribe((res: Response) => {
            this.res = res.json();
        });
    }
}
