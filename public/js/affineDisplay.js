export const displayAffine = (elm) => {
    return `
    <div class="input-group mb-3">
    <input type="text" class="form-control affinekey-${elm}" placeholder="nhap so a" aria-label="Username">
    <br />
    <input type="text" class="form-control affinekey-${elm}" placeholder="nhap so b" aria-label="Server">
    </div>
    `;
}